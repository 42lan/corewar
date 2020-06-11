/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ini_battle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:23:59 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/11 13:27:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_battle.h"

t_cw_proc	*cw_vm_ini_processus(int id, int pos)
{
	t_cw_proc *processus;

	if (!(processus = (t_cw_proc *)malloc(sizeof(t_cw_proc))))
		return (NULL);
	ft_printf("{yellow}je suis dans cw_vm_ini %p id = %d{}\n", *processus, id);
	id++;
	processus->carry = false;
	processus->opc = -1;
	processus->last_live = -1;
	processus->wait_cycles = 0;
	processus->pos = pos;
	processus->jump = -1;
	processus->id = id;
	ft_bzero(processus->regs, sizeof(int) * CW_REG_NUMBER);
	processus->regs[0] = id * -1;
	processus->next = NULL;
	return (processus);
}

void	cw_vm_ini_cycle_opc(t_cw_battle *battle)
{
	battle->cycle_opc[0] = 10;
	battle->cycle_opc[1] = 5;
	battle->cycle_opc[2] = 5;
	battle->cycle_opc[3] = 10;
	battle->cycle_opc[4] = 10;
	battle->cycle_opc[5] = 6;
	battle->cycle_opc[6] = 6;
	battle->cycle_opc[7] = 6;
	battle->cycle_opc[8] = 20;
	battle->cycle_opc[9] = 25;
	battle->cycle_opc[10] = 25;
	battle->cycle_opc[11] = 800;
	battle->cycle_opc[12] = 10;
	battle->cycle_opc[13] = 50;
	battle->cycle_opc[14] = 1000;
	battle->cycle_opc[15] = 2;
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

void	cw_vm_ini_battle_helper(t_cw_battle *battle, t_cw_vm *vm)
{
	battle->last_alive = vm->data.nbr_players - 1;
	battle->cycles_count = 0;
	battle->cycle_to_die = CW_CYCLE_TO_DIE;
	battle->check_performed = 0;
	battle->count_last_live = 0;
	cw_vm_ini_cycle_opc(battle);
	cw_vm_ini_byte_codage(battle);
}

void	cw_vm_ini_battle(t_cw_battle *battle, t_cw_vm *vm)
{
	int 			i;
	t_cw_proc 	*ptr;

	i = vm->data.nbr_players - 1;
	cw_vm_ini_battle_helper(battle, vm);
	if ((battle->procs = cw_vm_ini_processus(i, vm->players[i].init_pos)) == NULL)
		return ; // FAIRE UN TRUC DERREUR
	ptr = battle->procs;
	while (--i > -1)
	{
		if ((battle->procs->next = cw_vm_ini_processus(i, vm->players[i].init_pos)) == NULL)
		{
			return ;// FAIRE UN TRUC DERREUR
		}
		battle->procs = battle->procs->next;
	}
	battle->procs = ptr;
	battle->head = ptr;
}
