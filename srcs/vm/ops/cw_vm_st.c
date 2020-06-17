/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:32:09 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/17 01:49:38 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_inst.h"

static void		cw_vm_op_st_ind_exec(t_cw_vm *vm)
{
	int			reg_value;
	int			reg_index;
	int			arg_pos;
	int16_t		arg_val;

	reg_index = vm->arena[(vm->game.procs->pos + 2) % CW_MEM_SIZE];
	if (cw_vm_is_reg(reg_index) == TRUE)
	{
		reg_value = vm->game.procs->regs[reg_index - 1];
		arg_pos = (vm->game.procs->pos + 3) % CW_MEM_SIZE;
		arg_val = cw_vm_bigendian16_read(vm->arena, arg_pos);
		arg_val = (vm->game.procs->pos
				+ (arg_val % CW_IDX_MOD)) % CW_MEM_SIZE;
		if (arg_val < 0)
			arg_val += CW_MEM_SIZE;
		cw_vm_bigendian32_write(vm->arena, arg_val, reg_value);
	}
}

/*
** This instruction stores the value of the first argument in the second
*/

void			cw_vm_op_st(t_cw_vm *vm)
{
	int			arg_val[2];

	if (vm->inst.args_count >= 2 && vm->inst.types[0] == T_REG
			&& vm->inst.types[1] != T_DIR)
	{
		if (vm->inst.types[1] == T_REG)
		{
			arg_val[0] = vm->arena[(vm->game.procs->pos + 2) % CW_MEM_SIZE];
			arg_val[1] = vm->arena[(vm->game.procs->pos + 3) % CW_MEM_SIZE];
			if (cw_vm_is_reg(arg_val[0]) == TRUE && cw_vm_is_reg(arg_val[1]))
				vm->game.procs->regs[
					arg_val[1] - 1] = vm->game.procs->regs[arg_val[0] - 1];
		}
		else if (vm->inst.types[1] == T_IND)
			cw_vm_op_st_ind_exec(vm);
	}
	vm->game.procs->pos = (vm->game.procs->pos + 2
			+ cw_vm_add_pos(&vm->inst, 2, CW_DIR_SIZE_ST)) % CW_MEM_SIZE;
}
