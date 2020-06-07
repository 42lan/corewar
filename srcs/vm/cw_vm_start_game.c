/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 19:14:23 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 19:14:23 by jthierce         ###   ########.fr       */
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
		ft_printf("{blue}Hey battle->processus = %d\n", battle->processus->id);
		if (vm->arena[battle->processus->position] < 17
			&& vm->arena[battle->processus->position] > 0)
			battle->processus->op_code = vm->arena[battle->processus->position];
		if (battle->processus->next != NULL)
			battle->processus = battle->processus->next;
		else
			battle->processus = ptr;
	}
}