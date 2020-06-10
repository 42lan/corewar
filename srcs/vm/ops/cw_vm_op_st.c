/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:32:09 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/09 19:32:09 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_st_ind_exec(t_cw_battle *battle, t_cw_vm *vm)
{
	int 	reg_value;
	int 	reg_index;
	int		i;
	int16_t arg2;
	int		multiplier;

	i = -1;
	arg2 = 0;
	multiplier = 256;
	reg_index = vm->arena[(battle->processus->position + 2) % CW_MEM_SIZE];
	if (reg_index < 1 || reg_index > 16)
		ft_printf("ERROR\n");
	reg_value = battle->processus->registries[reg_index - 1];
	while (++i < 2)
	{
		arg2 += multiplier * vm->arena[(battle->processus->position + 3 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	arg2 = battle->processus->position + (arg2 % CW_IDX_MOD);
	if (arg2 < 0)
		arg2 += CW_MEM_SIZE;
	vm->arena[(arg2) % CW_MEM_SIZE] = reg_value / ft_pow(256, 3);
	reg_value = reg_value % ft_pow(256, 3);
	vm->arena[(arg2 + 1) % CW_MEM_SIZE] = reg_value / ft_pow(256, 2);
	reg_value = reg_value % ft_pow(256, 2);
	vm->arena[(arg2 + 2) % CW_MEM_SIZE] = reg_value / 256;
	reg_value = reg_value % 256;
	vm->arena[(arg2 + 3) % CW_MEM_SIZE] = reg_value;
	battle->processus->position += 5;
}


void	cw_vm_op_st(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
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
	else if (inst->types[1] == T_IND)
		cw_vm_op_st_ind_exec(battle, vm);
	cw_vm_arena_dump(vm->arena, CW_MEM_SIZE);
	exit(1);
}