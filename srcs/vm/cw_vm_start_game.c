/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 19:14:23 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/14 12:35:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_game.h"
#include "cw_vm.h"

static int		cw_vm_last_proc(t_cw_game *game, t_cw_vm *vm)
{
	int			id;
	char		*name;

	id = game->last_alive;
	name = vm->players[id].champion->name;
	ft_printf("{bold}{orange}The player %d(%s) has won.{}\n", id, name);
	(vm->dump == true) ? cw_vm_arena_dump(vm->arena, CW_MEM_SIZE) : 0;
	return (CW_VM_LAST_PROC);

}

static int		cw_vm_processus_dead(t_cw_game *game, t_cw_proc *proc,
					t_cw_vm *vm)
{
	t_cw_proc	*prev;

	while (proc != NULL)
	{
		if (proc->last_live == -1)
		{
			if (proc == game->head)
			{
				if (proc->next == NULL)
					return (cw_vm_last_proc(game, vm));
				game->head = proc->next;
			}
			else
				prev->next = proc->next;
			ft_memdel((void **)&proc);
		}
		else
		{
			proc->last_live = -1;
			prev = proc;
			proc = proc->next;
		}
	}
	return (CW_VM_NOT_LAST_PROC);
}

static int		cw_vm_perform_check(t_cw_game *game, t_cw_vm *vm)
{
	game->check_performed++;
	game->cycles_count++;
	if (game->cycles_count >= game->cycle_to_die)
	{
		game->check_performed++;
		if (cw_vm_processus_dead(game, game->head, vm) == CW_VM_LAST_PROC)
			return (CW_VM_LAST_PROC);
		if (game->check_performed >= CW_MAX_CHECKS
			|| game->count_last_live >= CW_NBR_LIVE)
		{
			game->cycle_to_die -= CW_CYCLE_DELTA;
			game->check_performed = 0;
		}
		game->count_last_live = 0;
		game->cycles_count = 0;
	}
	game->procs = game->head;
	return (CW_VM_NOT_LAST_PROC);
}

void	cw_vm_start_game(t_cw_game *game, t_cw_vm *vm)
{
	while (1)
	{
		if (game->procs->wait_cycles != 0)
		{
			game->procs->wait_cycles--;
			if (game->procs->wait_cycles == 0)
				cw_vm_read_execute(game, vm);
		}
		else if (cw_vm_is_valid_op(vm->arena[game->procs->pos]) == true)
		{
			game->procs->opc = vm->arena[game->procs->pos];
			game->procs->wait_cycles = game->cycle_opc[game->procs->opc - 1];
		}
		else
			game->procs->pos = (game->procs->pos + 1) % CW_MEM_SIZE;
		if (game->procs->next != NULL)
			game->procs = game->procs->next;
		else
			if (cw_vm_perform_check(game, vm) == CW_VM_LAST_PROC)
				break ;
	}
}
