/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 19:14:23 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/08 17:52:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_battle.h"
#include "cw_vm.h"

void	cw_vm_processus_dead(t_cw_battle *battle, t_cw_proc *proc)
{
	t_cw_proc *prev;

	while (proc != NULL)
	{
		if (proc->last_live == -1)
		{
			if (proc == battle->head)
			{
				if (proc->next == NULL)
				{
					ft_printf("{bold}{red}FIN DU MATCH\n{}");
					exit (1);
				}
				battle->head = proc->next;
			}
			else
				prev->next = proc->next;
			free(proc);
			proc = NULL;
		}
		else
		{
			proc->last_live = -1;
			prev = proc;
			proc = proc->next;
		}
	}
}

void	cw_vm_start_game(t_cw_battle *battle, t_cw_vm *vm)
{
	while (1)
	{
		if (battle->procs->wait_cycles != 0)
		{
			ft_printf("{green}%d\n{}", battle->procs->wait_cycles);
			battle->procs->wait_cycles--;
			if (battle->procs->wait_cycles == 0)
			{
				cw_vm_read_execute(battle, vm);
			}
		}
		else if (vm->arena[battle->procs->pos] < 17
				&& vm->arena[battle->procs->pos] > 0)
		{
			battle->procs->opc = vm->arena[battle->procs->pos];
			battle->procs->wait_cycles = battle->cycle_opc[battle->procs->opc - 1];
		}
		else
			battle->procs->pos = (battle->procs->pos + 1) % CW_MEM_SIZE;
		if (battle->procs->next != NULL)
			battle->procs = battle->procs->next;
		else
		{
			battle->check_performed++;
			battle->cycles_count++;
			if (battle->cycles_count == CW_CYCLE_TO_DIE)
				cw_vm_processus_dead(battle, battle->head);
			battle->procs = battle->head;
		}
	}
}
