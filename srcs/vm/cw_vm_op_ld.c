/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_ld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 01:22:20 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/09 01:22:20 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_ld_dir_exec(t_cw_battle *battle, t_cw_vm *vm)
{
	unsigned int	multiplier;
	int				i;
	unsigned int	arg1;

	i = -1;
	arg1 = 0;
	multiplier = 256 * 256 * 256;
	while (++i < CW_DIR_SIZE_LD - 1)
	{
		arg1 += multiplier * vm->arena[battle->processus->position + 2 + i];
		multiplier /= 256;
	}
	ft_printf("{red} ARG1 = %d\n{}", arg1);
	exit(1);
}

void	cw_vm_op_ld(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	if (inst->args_count != 2)
		ft_printf("ERROR\n");
	if (inst->types[0] == T_REG || inst->types[1] != T_REG)	
		ft_printf("ERROR\n");
	if (inst->types[0] == T_DIR)
		cw_vm_op_ld_dir_exec(battle, vm);
	//else
}
