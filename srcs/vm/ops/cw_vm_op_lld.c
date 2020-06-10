/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_lld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:14:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 19:03:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_lld_dir_exec(t_cw_battle *battle, t_cw_vm *vm)
{
	int				i;
	int32_t			arg1;
	int				index;
	unsigned int	multiplier;

	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, CW_DIR_SIZE_LLD - 1);
	while (++i < CW_DIR_SIZE_LLD)
	{
		arg1 += multiplier * vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	index = vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE] - 1;
	(cw_vm_is_reg(index) == false) ? ft_printf("ERROR\n") : 0;
	battle->processus->registries[index] = arg1;
}

void	cw_vm_op_lld_ind_exec(t_cw_battle *battle, t_cw_vm *vm)
{
	int				i;
	int16_t			arg1;
	unsigned int	multiplier;
	int				to_address;
	int				index;

	i = -1;
	arg1 = 0;
	multiplier = 256;
	while (++i < 2)
	{
		arg1 += multiplier * vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	to_address = (battle->processus->position + arg1) % CW_MEM_SIZE;
	(to_address < 0) ? to_address += CW_MEM_SIZE : 0;
	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, 3);
	while (++i < 4)
	{
		arg1 += multiplier * vm->arena[(to_address + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	index = vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE];
	battle->processus->registries[index - 1] = arg1;
	battle->processus->carry = (arg1 == 0) ? 1 : 0;
}

void	cw_vm_op_lld(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int		pos;

	if (inst->args_count != 2 || inst->types[0] == T_REG || inst->types[1] != T_REG)	
		ft_printf("ERROR\n");
	if (inst->types[0] == T_DIR)
		cw_vm_op_lld_dir_exec(battle, vm);
	else if (inst->types[0] == T_IND)
		cw_vm_op_lld_ind_exec(battle, vm);
	pos = (inst->types[0] == T_DIR) ? 7 : 5;
	battle->processus->position += pos % CW_MEM_SIZE;
}
