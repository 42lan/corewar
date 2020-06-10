/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:04:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 17:47:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_add(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int		arg[3];

	if (inst->args_count != 3 || inst->types[0] != T_REG || inst->types[1] == T_REG || inst->types[2] != T_REG)
		ft_printf("ERROR\n");
	arg[0] = battle->processus->registries[vm->arena[(battle->processus->position + 2) % CW_MEM_SIZE] - 1];
	arg[1] = battle->processus->registries[vm->arena[(battle->processus->position + 3) % CW_MEM_SIZE] - 1];
	arg[2] = arg[0] + arg[1];
	battle->processus->registries[vm->arena[(battle->processus->position + 4) % CW_MEM_SIZE] - 1] = arg[2];
	battle->processus->carry = (arg[2] == 0) ? 1 : 0;
	battle->processus->position = (battle->processus->position + 2) % CW_MEM_SIZE;
}
