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

t_cw_processus	*cw_vm_ini_processus(int id, int position)
{
	t_cw_processus *processus;

	if (!(processus = (t_cw_processus *)malloc(sizeof(t_cw_processus))))
		return (NULL);
	ft_printf("{yellow}je suis dans cw_vm_ini %p id = %d{}\n", *processus, id);
	processus->id = id;
	processus->position = position;
	processus->op_code = -1;
	processus->last_live = -1;
	processus->wait_cycles = -1;
	processus->jump = -1;
	processus->carry = false;
	processus->next = NULL;
	return (processus);
}

void	cw_vm_ini_battle(t_cw_battle *battle, t_cw_vm *vm)
{
	t_cw_processus 	*ptr;
	int 			i;

	ptr = NULL;
	i = vm->data.nbr_players - 1;
	battle->check_performed = 0;
	battle->cycles_count = 0;
	battle->count_last_live = 0;
	battle->last_alive = vm->data.nbr_players - 1;
	battle->cycle_to_die = CW_CYCLE_TO_DIE;
	if ((battle->processus = cw_vm_ini_processus(i, vm->players[i].initial_position)) == NULL)
		return ; // FAIRE UN TRUC DERREUR
	ptr = battle->processus;
	while (--i > -1)
	{
		if ((battle->processus->next = cw_vm_ini_processus(i, vm->players[i].initial_position)) 
		== NULL)
		{
			return ;// FAIRE UN TRUC DERREUR
		}
		battle->processus = battle->processus->next;
	}
	battle->processus = ptr;
}
