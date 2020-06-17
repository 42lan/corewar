/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 01:22:20 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/17 01:46:07 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_inst.h"

static void		cw_vm_op_ld_dir_exec(t_cw_vm *vm)
{
	int			index;
	int			arg_pos;
	int32_t		arg_val;

	arg_pos = (vm->game.procs->pos + 2) % CW_MEM_SIZE;
	arg_val = cw_vm_bigendian32_read(vm->arena, arg_pos);
	index = vm->arena[(vm->game.procs->pos + 6) % CW_MEM_SIZE];
	if (cw_vm_is_reg(index) == TRUE)
	{
		vm->game.procs->regs[index - 1] = arg_val;
		vm->game.procs->carry = (arg_val == 0) ? 1 : 0;
	}
}

static void		cw_vm_op_ld_ind_exec(t_cw_vm *vm)
{
	int			index;
	int			value;
	int			idx_address;
	int			arg_pos;
	int16_t		arg_val;

	arg_pos = (vm->game.procs->pos + 2) % CW_MEM_SIZE;
	arg_val = cw_vm_bigendian16_read(vm->arena, arg_pos);
	idx_address = (vm->game.procs->pos + (arg_val % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	index = vm->arena[(vm->game.procs->pos + 4) % CW_MEM_SIZE];
	if (cw_vm_is_reg(index) == TRUE)
	{
		value = cw_vm_bigendian32_read(vm->arena, idx_address);
		vm->game.procs->regs[index - 1] = value;
		vm->game.procs->carry = (value == 0) ? 1 : 0;
	}
}

/*
** This instruction loads the value of the first parameter in the register
*/

void			cw_vm_op_ld(t_cw_vm *vm)
{
	if (vm->inst.args_count >= 2 && vm->inst.types[0] != T_REG
		&& vm->inst.types[1] == T_REG)
	{
		if (vm->inst.types[0] == T_DIR)
			cw_vm_op_ld_dir_exec(vm);
		else if (vm->inst.types[0] == T_IND)
			cw_vm_op_ld_ind_exec(vm);
	}
	vm->game.procs->pos = (vm->game.procs->pos + 2
		+ cw_vm_add_pos(&vm->inst, 2, CW_DIR_SIZE_LD)) % CW_MEM_SIZE;
}
