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

void	cw_vm_start_game(t_cw_battle *battle, t_cw_vm *vm)
{
	t_cw_processus *ptr;

	ptr = battle->processus;
	while (1)
	{
		if (battle->processus->wait_cycles != 0)
		{
			ft_printf("{green}%d\n{}", battle->processus->wait_cycles);
			battle->processus->wait_cycles--;
			if (battle->processus->wait_cycles == 0)
			{
				cw_vm_read_execute(battle, vm);
			}
		}
		else if (vm->arena[battle->processus->position] < 17
				&& vm->arena[battle->processus->position] > 0)
		{
			battle->processus->op_code = vm->arena[battle->processus->position];
			battle->processus->wait_cycles = battle->cycle_op_code[battle->processus->op_code - 1];
		}
		else
			battle->processus->position = (battle->processus->position + 1) % CW_MEM_SIZE;
		if (battle->processus->next != NULL)
			battle->processus = battle->processus->next;
		else
			battle->processus = ptr;
	}
}
