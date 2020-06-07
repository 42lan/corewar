/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ini_battle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:23:59 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 15:23:59 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_battle.h"

int		cw_vm_ini_processus(t_cw_processus *processus, int id)
{
	if (!(processus = (t_cw_processus *)malloc(sizeof(t_cw_processus))))
		return (CW_ERROR_MALLOC_FAILED);
	ft_printf("{white}LUKE JE SUIS TON PERE\n{}");
	processus->id = id;
	processus->op_code = -1;
	processus->last_live = -1;
	processus->wait_cycles = -1;
	processus->position = -1;
	processus->jump = -1;
	processus->carry = false;
	processus->next = NULL;
	return (CW_SUCCESS);
}

void	cw_vm_ini_battle(t_cw_battle *battle, t_cw_vm *vm)
{
	t_cw_processus 	*ptr;
	int 			i;

	ptr = NULL;
	i = vm->data.nbr_players;
	battle->check_performed = 0;
	battle->cycles_count = 0;
	battle->count_last_live = 0;
	battle->last_alive = vm->data.nbr_players - 1;
	battle->cycle_to_die = CW_CYCLE_TO_DIE;
	while (--i != -1)
	{
		if (cw_vm_ini_processus(battle->processus, i) == CW_ERROR_MALLOC_FAILED)
		{
			battle->processus = ptr;
			while (battle->processus != NULL)
			{
				ptr = battle->processus->next;
				free(battle->processus);
				ptr = battle->processus;
			}
		}
		if (i == vm->data.nbr_players - 1)
			ptr = battle->processus;
		battle->processus = battle->processus->next;
	}
	battle->processus = ptr;
}
