/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 19:14:23 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/12 15:36:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_battle.h"
#include "cw_vm.h"

static int		cw_vm_last_proc(t_cw_battle *battle, t_cw_vm *vm)
{
	int			id;
	char		*name;

	id = battle->last_alive;
	name = vm->players[battle->last_alive].champion->name;
	ft_printf("{bold}{orange}The player %d(%s) has won.{}\n", id, name);
	(vm->dump == true) ? cw_vm_arena_dump(vm->arena, CW_MEM_SIZE) : 0;
	return (CW_VM_LAST_PROC);

}

static int		cw_vm_processus_dead(t_cw_battle *battle, t_cw_proc *proc, t_cw_vm *vm)
{
	t_cw_proc	*prev;

	while (proc != NULL)
	{
		if (proc->last_live == -1)
		{
			if (proc == battle->head)
			{
				if (proc->next == NULL)
					return (cw_vm_last_proc(battle, vm));
				battle->head = proc->next;
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

static int		cw_vm_perform_check(t_cw_battle *battle, t_cw_vm *vm)
{
	battle->check_performed++;
	battle->cycles_count++;
	if (battle->cycles_count >= battle->cycle_to_die)
	{
		battle->check_performed++;
		if (cw_vm_processus_dead(battle, battle->head, vm) == CW_VM_LAST_PROC)
			return (CW_VM_LAST_PROC);
		if (battle->check_performed >= CW_MAX_CHECKS || battle->count_last_live >= CW_NBR_LIVE)
		{
			battle->cycle_to_die -= CW_CYCLE_DELTA;
			battle->check_performed = 0;
		}
		battle->count_last_live = 0;
		battle->cycles_count = 0;
	}
	battle->procs = battle->head;
	return (CW_VM_NOT_LAST_PROC);
}

void	cw_vm_start_game(t_cw_battle *battle, t_cw_vm *vm)
{
	while (1)
	{
		if (battle->procs->wait_cycles != 0)
		{
			battle->procs->wait_cycles--;
			if (battle->procs->wait_cycles == 0)
				cw_vm_read_execute(battle, vm);
		}
		else if (cw_vm_is_valid_op(vm->arena[battle->procs->pos]) == true)
		{
			battle->procs->opc = vm->arena[battle->procs->pos];
			battle->procs->wait_cycles = battle->cycle_opc[battle->procs->opc - 1];
		}
		else
			battle->procs->pos = (battle->procs->pos + 1) % CW_MEM_SIZE;
		if (battle->procs->next != NULL)
			battle->procs = battle->procs->next;
		else
			if (cw_vm_perform_check(battle, vm) == CW_VM_LAST_PROC)
				break ;
	}
}
