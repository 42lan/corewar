/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 19:14:23 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/17 05:15:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"

static int	cw_vm_last_proc(t_cw_game *game, t_cw_vm *vm, t_cw_proc *proc)
{
	int			id;
	char		*name;

	id = game->last_alive;
	name = vm->players[id].champion->name;
	ft_printf("{bold}{orange}The player %d(%s) has won.{}\n", id + 1, name);
	ft_memdel((void **)&proc);
	return (CW_LAST_PROC);
}

static int	cw_vm_processus_dead(t_cw_game *game, t_cw_proc *proc, t_cw_vm *vm)
{
	t_cw_proc	*prev;
	t_cw_proc	*tmp;

	while (proc != NULL)
	{
		tmp = proc->next;
		if (proc->last_live == -1)
		{
			if (proc == game->head)
			{
				if (proc->next == NULL)
					return (cw_vm_last_proc(game, vm, proc));
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
		}
		proc = tmp;
	}
	return (CW_NOT_LAST_PROC);
}

static int	cw_vm_perform_check(t_cw_vm *vm, t_cw_game *game)
{
	vm->dump--;
	game->cycles_count++;
	if (vm->dump == 0)
	{
		cw_vm_arena_dump(vm->arena, CW_MEM_SIZE);
		cw_vm_procs_destroy(game->head);
		return (CW_VM_DUMP);
	}
	if (game->cycles_count >= game->cycle_to_die)
	{
		game->check_performed++;
		if (cw_vm_processus_dead(game, game->head, vm) == CW_LAST_PROC)
			return (CW_LAST_PROC);
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
	return (CW_NOT_LAST_PROC);
}

int			cw_vm_start_game(t_cw_vm *vm, t_cw_game *game)
{
	int			ret;

	while (1)
	{
		if (game->procs->wait_cycles != 0)
		{
			game->procs->wait_cycles--;
			(game->procs->wait_cycles == 0) ? cw_vm_read_execute(vm) : 0;
		}
		else if (cw_vm_is_valid_op(vm->arena[game->procs->pos]) == TRUE)
		{
			game->procs->opc = vm->arena[game->procs->pos];
			game->procs->wait_cycles = game->cycle_opc[game->procs->opc - 1] - 1;
		}
		else
			game->procs->pos = (game->procs->pos + 1) % CW_MEM_SIZE;
		if (game->procs->next != NULL)
			game->procs = game->procs->next;
		else
		{
			if ((ret = cw_vm_perform_check(vm, game)) != CW_NOT_LAST_PROC)
				break ;
		}
	}
	return ((ret == CW_VM_DUMP) || (ret == CW_LAST_PROC) ? CW_SUCCESS : ret);
}
