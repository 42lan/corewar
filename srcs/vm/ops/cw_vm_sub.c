/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:01:49 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/11 14:44:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_sub(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int		arg[3];

	if (inst->args_count != 3)
		ft_printf("ERROR\n");
	if (inst->types[0] != T_REG || inst->types[1] != T_REG || inst->types[2] != T_REG)	
		ft_printf("ERROR\n");
	arg[0] = battle->procs->regs[vm->arena[(battle->procs->pos + 2) % CW_MEM_SIZE] - 1];
	arg[1] = battle->procs->regs[vm->arena[(battle->procs->pos + 3) % CW_MEM_SIZE] - 1];
	arg[2] = arg[0] - arg[1];
	battle->procs->regs[vm->arena[(battle->procs->pos + 4) % CW_MEM_SIZE] - 1] = arg[2];
	battle->procs->carry = (arg[2] == 0) ? 1 : 0;
	battle->procs->pos = (battle->procs->pos + 5) % CW_MEM_SIZE;
}
