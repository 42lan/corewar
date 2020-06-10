/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:19:21 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 17:39:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_or_body(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int i;
	int	pos;
	int tmp;
	int reg_value;
	int	arg[3];

	i = -1;
	pos = 1;
	reg_value = 0;
	while (++i < 2)
	{
		// RECUP ARGS
		if (inst->args[i] == T_REG)
		{
			if (cw_vm_is_reg(vm->arena[battle->processus->position + pos + i]) == false)
				ft_printf("ERROR\n");
			arg[i] = battle->processus->registries[(vm->arena[battle->processus->position + pos + i]) - 1];
			pos++;
		}
		else if (inst->args[i] == T_DIR)
		{
			//
			pos += CW_DIR_SIZE_OR;
		}
		else if (inst->args[i] == T_IND)
		{
			//
			pos += 2;
		}
	}
	// OR CORE
	battle->processus->registries[battle->processus->position + pos - 1] = reg_value;
	battle->processus->carry = (reg_value == 0) ? 1 : 0;
	battle->processus->position = pos + 1;
}

void	cw_vm_op_or(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	(void)inst;(void)battle;(void)vm;
	if (inst->args_count != 3 || inst->types[2] != T_REG)	
		ft_printf("ERROR\n");
	cw_vm_op_or_body(inst, battle, vm);
}
