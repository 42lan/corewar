/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_sti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:13:22 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 22:48:59 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_sti(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	if (inst->args_count != 2)
		ft_printf("ERROR\n");
	if (inst->types[0] != T_REG || inst->types[1] == T_DIR)	
		ft_printf("ERROR\n");
	if (inst->types[1] == T_REG)
	{
		battle->processus->registries[vm->arena[(battle->processus->position + 3) % CW_MEM_SIZE] - 1] =
		battle->processus->registries[vm->arena[(battle->processus->position + 2) % CW_MEM_SIZE] - 1];
		battle->processus->position += 4;
	}
		// rajouter une protection si la valeur de l'index est superieur a 16 ou < 1
	//else if (inst->types[1] == T_IND)
	//	cw_vm_op_st_ind_exec(battle, vm);
	cw_vm_arena_dump(vm->arena, CW_MEM_SIZE);
}
