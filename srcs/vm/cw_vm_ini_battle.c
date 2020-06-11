/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ini_battle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:23:59 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/11 13:09:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_battle.h"

t_cw_processus	*cw_vm_ini_processus(int id, int position)
{
	t_cw_processus *processus;

	if (!(processus = (t_cw_processus *)malloc(sizeof(t_cw_processus))))
		return (NULL);
	ft_printf("{yellow}je suis dans cw_vm_ini %p id = %d{}\n", *processus, id);
	processus->carry = false;
	processus->op_code = -1;
	processus->last_live = -1;
	processus->wait_cycles = 0;
	processus->position = position;
	processus->jump = -1;
	processus->id = id;
	ft_bzero(processus->registries, sizeof(int) * CW_REG_NUMBER);
	processus->next = NULL;
	return (processus);
}

void	cw_vm_ini_cycle_op_code(t_cw_battle *battle)
{
	battle->cycle_op_code[0] = 10;
	battle->cycle_op_code[1] = 5;
	battle->cycle_op_code[2] = 5;
	battle->cycle_op_code[3] = 10;
	battle->cycle_op_code[4] = 10;
	battle->cycle_op_code[5] = 6;
	battle->cycle_op_code[6] = 6;
	battle->cycle_op_code[7] = 6;
	battle->cycle_op_code[8] = 20;
	battle->cycle_op_code[9] = 25;
	battle->cycle_op_code[10] = 25;
	battle->cycle_op_code[11] = 800;
	battle->cycle_op_code[12] = 10;
	battle->cycle_op_code[13] = 50;
	battle->cycle_op_code[14] = 1000;
	battle->cycle_op_code[15] = 2;
}

void	cw_vm_ini_byte_codage(t_cw_battle *battle)
{
	battle->byte_codage[0] = 0;
	battle->byte_codage[1] = 1;
	battle->byte_codage[2] = 1;
	battle->byte_codage[3] = 1;
	battle->byte_codage[4] = 1;
	battle->byte_codage[5] = 1;
	battle->byte_codage[6] = 1;
	battle->byte_codage[7] = 1;
	battle->byte_codage[8] = 0;
	battle->byte_codage[9] = 1;
	battle->byte_codage[10] = 1;
	battle->byte_codage[11] = 0;
	battle->byte_codage[12] = 1;
	battle->byte_codage[13] = 1;
	battle->byte_codage[14] = 0;
	battle->byte_codage[15] = 1;
}

void	cw_vm_ini_battle(t_cw_battle *battle, t_cw_vm *vm)
{
	int 			i;
	t_cw_processus 	*ptr;

	ptr = NULL;
	i = vm->data.nbr_players - 1;
	battle->last_alive = vm->data.nbr_players - 1;
	battle->cycles_count = 0;
	battle->cycle_to_die = CW_CYCLE_TO_DIE;
	battle->check_performed = 0;
	battle->count_last_live = 0;
	cw_vm_ini_cycle_op_code(battle);
	cw_vm_ini_byte_codage(battle);
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
	battle->head = ptr;
}
