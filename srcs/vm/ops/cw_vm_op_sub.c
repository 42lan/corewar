/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:01:49 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/10 00:01:49 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

 void	cw_vm_op_sub(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int		arg1;
	int		arg2;
	int		arg3;

	if (inst->args_count != 3)
		ft_printf("ERROR\n");
	if (inst->types[0] != T_REG || inst->types[1] != T_REG || inst->types[2] != T_REG)	
		ft_printf("ERROR\n");
	arg1 = battle->processus->registries[vm->arena[(battle->processus->position + 2) % CW_MEM_SIZE] - 1];
	arg2 = battle->processus->registries[vm->arena[(battle->processus->position + 3) % CW_MEM_SIZE] - 1];
	arg3 = arg1 - arg2;
	battle->processus->registries[vm->arena[(battle->processus->position + 4) % CW_MEM_SIZE] - 1] = arg3;
	battle->processus->carry = (arg3 == 0) ? 1 : 0;
	battle->processus->position = (battle->processus->position + 5) % CW_MEM_SIZE;
}
