/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:32:09 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/12 08:53:26 by jthierce         ###   ########.fr       */
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
	reg_index = vm->arena[(battle->procs->pos + 2) % CW_MEM_SIZE];
	if (reg_index < 1 || reg_index > 16)
		ft_printf("ERROR\n");
	reg_value = battle->procs->regs[reg_index - 1];
	while (++i < 2)
	{
		arg2 += multiplier * vm->arena[(battle->procs->pos + 3 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	arg2 = battle->procs->pos + (arg2 % CW_IDX_MOD);
	if (arg2 < 0)
		arg2 += CW_MEM_SIZE;
	ft_bigendian32_write(vm->arena + (arg2) % CW_MEM_SIZE, reg_value);
	battle->procs->pos += 5;
}


void	cw_vm_op_st(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	if (inst->args_count != 2)
		ft_printf("ERROR\n");
	if (inst->types[0] != T_REG || inst->types[1] == T_DIR)	
		ft_printf("ERROR\n");
	if (inst->types[1] == T_REG)
	{
		if (vm->arena[(battle->procs->pos + 3) % CW_MEM_SIZE] > 16 || vm->arena[(battle->procs->pos + 3) % CW_MEM_SIZE] < 1
		|| vm->arena[(battle->procs->pos + 2) % CW_MEM_SIZE] > 16 || vm->arena[(battle->procs->pos + 2) % CW_MEM_SIZE] < 1)
		{
			ft_printf("ERROR\n");
		}
		battle->procs->regs[vm->arena[(battle->procs->pos + 3) % CW_MEM_SIZE] - 1] =
		battle->procs->regs[vm->arena[(battle->procs->pos + 2) % CW_MEM_SIZE] - 1];
		battle->procs->pos += 4;
	}
	else if (inst->types[1] == T_IND)
		cw_vm_op_st_ind_exec(battle, vm);
}
