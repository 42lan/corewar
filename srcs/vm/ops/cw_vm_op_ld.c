/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_ld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 01:22:20 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/09 16:24:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_ld_dir_exec(t_cw_battle *battle, t_cw_vm *vm)
{
	int				i;
	int				index;
	int32_t			arg1;
	unsigned int	multiplier;

	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, CW_DIR_SIZE_LD - 1);
	while (++i < CW_DIR_SIZE_LD)
	{
		arg1 += multiplier * vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	index = vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE];
	if (index < 1 || index > CW_REG_NUMBER)
		ft_printf("ERROR\n");
	battle->processus->registries[index - 1] = arg1;
	battle->processus->carry = (arg1 == 0) ? 1 : 0;
	battle->processus->position = (battle->processus->position + 7) % CW_MEM_SIZE;//A REVOIR
	ft_printf("{red}battle->processus->position = %d\n", battle->processus->position);
}

void	cw_vm_op_ld_ind_exec(t_cw_battle *battle, t_cw_vm *vm)
{
	int				i;
	int				index;
	int16_t			arg1;
	unsigned int	multiplier;
	int				idx_address;

	i = -1;
	arg1 = 0;
	multiplier = 256;
	while (++i < 2)
	{
		arg1 += multiplier * vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	idx_address = (battle->processus->position + (arg1 % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	index = vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE];
	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, 3);
	while (++i < 4)
	{
		arg1 += multiplier * vm->arena[(idx_address + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	battle->processus->registries[index - 1] = arg1;
	battle->processus->carry = (arg1 == 0) ? 1 : 0;
	battle->processus->position = (battle->processus->position + 5) % CW_MEM_SIZE;//A REVOIR
}

void	cw_vm_op_ld(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	if (inst->args_count != 2)
		ft_printf("ERROR\n");
	if (inst->types[0] == T_REG || inst->types[1] != T_REG)	
		ft_printf("ERROR\n");
	if (inst->types[0] == T_DIR)
		cw_vm_op_ld_dir_exec(battle, vm);
	else if (inst->types[0] == T_IND)
		cw_vm_op_ld_ind_exec(battle, vm);
}
