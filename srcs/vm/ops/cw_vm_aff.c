/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:15:23 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 18:22:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_aff(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int		arg1;
	int		index;
	char	reg_value;

	if (inst->args_count != 1 || inst->types[0] != T_REG)
		ft_printf("ERROR\n");
	index = vm->arena[battle->procs->pos + 2] - 1;
	arg1 = battle->procs->regs[index];
	reg_value = arg1 % 256;
	ft_printf("{bold}{red}%c{}\n", reg_value);
	battle->procs->pos += 3 % CW_MEM_SIZE;
}
