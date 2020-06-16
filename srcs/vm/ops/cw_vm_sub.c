/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:01:49 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/16 04:46:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_inst.h"

/*
** This instruction substracts the contents of the 2 first and stores the result
** in the third
*/

void		cw_vm_op_sub(t_cw_vm *vm)
{
	int		regs[3];
	int		arg_val[3];

	if (vm->inst.args_count >= 3 && vm->inst.types[0] == T_REG
			&& vm->inst.types[1] == T_REG && vm->inst.types[2] == T_REG)
	{
		regs[0] = vm->arena[(vm->game.procs->pos + 2) % CW_MEM_SIZE];
		regs[1] = vm->arena[(vm->game.procs->pos + 3) % CW_MEM_SIZE];
		regs[2] = vm->arena[(vm->game.procs->pos + 4) % CW_MEM_SIZE];
		if (cw_vm_is_reg(regs[0]) && cw_vm_is_reg(regs[1])
				&& cw_vm_is_reg(regs[2]))
		{
			arg_val[0] = vm->game.procs->regs[regs[0] - 1];
			arg_val[1] = vm->game.procs->regs[regs[1] - 1];
			arg_val[2] = arg_val[0] - arg_val[1];
			vm->game.procs->regs[regs[2] - 1] = arg_val[2];
			vm->game.procs->carry = (arg_val[2] == 0) ? 1 : 0;
		}
	}
	vm->game.procs->pos = (vm->game.procs->pos + 2
			+ cw_vm_add_pos(&vm->inst, 3, CW_DIR_SIZE_SUB)) % CW_MEM_SIZE;
}
