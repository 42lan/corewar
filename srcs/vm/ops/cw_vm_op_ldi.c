/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_ldi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:12:31 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 21:00:50 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

int		cw_vm_op_ldi_dir(t_cw_battle *battle, t_cw_vm *vm, int pos)
{
	int total;
	int i;
	int pow;

	i = -1;
	total = 0;
	pow = ft_pow(256, CW_DIR_SIZE_LDI - 1);
	while (++i < CW_DIR_SIZE_LDI)
	{
		total += pow * vm->arena[(battle->processus->position + pos + i) % CW_MEM_SIZE];
		pow /= 256;
	}
	return (total);
}

int16_t	cw_vm_op_ldi_ind(t_cw_battle *battle, t_cw_vm *vm, int pos)
{
	int				i;
	int16_t			arg;
	int				total;
	unsigned int	multiplier;
	int				idx_address;

	i = -1;
	arg = 0;
	total = 0;
	multiplier = 256;
	while (++i < 2)
	{
		arg += multiplier * vm->arena[(battle->processus->position + pos + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	idx_address = (battle->processus->position + (arg % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	i = -1;
	arg = 0;
	multiplier = ft_pow(256, 3);
	while (++i < 3)
	{
		total += multiplier * vm->arena[(idx_address + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	return (arg);
}

int		cw_vm_op_ldi_value_reg(t_cw_vm *vm, int pos)
{
	int i;
	int pow;
	int total;

	i = -1;
	pow = ft_pow(256, 3);
	while (++i < 4)
	{
		total = vm->arena[(pos + i) % CW_MEM_SIZE];
		pow /= 256;
	}
	return (total);
}

void	cw_vm_op_ldi_body(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int i;
	int	arg[3];
	int	pos;

	i = -1;
	pos = 2;
	while (++i < 2)
	{
		if (inst->args[i] == T_REG)
		{
			if ((vm->arena[battle->processus->position + pos]) < 1 || (vm->arena[battle->processus->position + pos]) > 16)
				ft_printf("ERROR\n");
			arg[i] = battle->processus->registries[(vm->arena[battle->processus->position + pos]) - 1];
			pos++;
		}
		else if (inst->args[i] == T_DIR)
		{
			arg[i] = cw_vm_op_ldi_dir(battle, vm, pos);
			pos += CW_DIR_SIZE_LDI;
		}
		else if (inst->args[i] == T_IND)
		{
			arg[i] = cw_vm_op_ldi_ind(battle, vm, pos);
			pos += 2;
		}
	}
	arg[0] = battle->processus->position + ((arg[0] + arg[1]) % CW_IDX_MOD);
	if (arg[0] < 0)
		arg[0] += CW_MEM_SIZE;
	battle->processus->registries[battle->processus->position + pos] = cw_vm_op_ldi_value_reg(vm, arg[0]);
}

void	cw_vm_op_ldi(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	if (inst->args_count != 3)
		ft_printf("ERROR\n");
	if (inst->types[2] != T_REG || inst->types[1] == T_IND)	
		ft_printf("ERROR\n");
	cw_vm_op_ldi_body(inst, battle, vm);
}
