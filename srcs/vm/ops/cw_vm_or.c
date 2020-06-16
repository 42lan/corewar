/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:15:08 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/16 02:44:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

static int		cw_vm_op_or_dir(t_cw_vm *vm, int *pos)
{
	int			arg_val;
	int			arg_pos;

	arg_pos = (vm->game.procs->pos + *pos) % CW_MEM_SIZE;
	arg_val = ft_bigendian32_read(vm->arena + arg_pos);
	*pos += CW_DIR_SIZE_OR;
	return (arg_val);
}

static int		cw_vm_op_or_ind(t_cw_vm *vm, int *pos)
{
	int			arg_val;
	int			idx_address;
	int16_t		arg_pos;

	arg_pos = (vm->game.procs->pos + *pos) % CW_MEM_SIZE;
	arg_val = ft_bigendian16_read(vm->arena + arg_pos);
	idx_address = (vm->game.procs->pos + (arg_val % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	arg_val = ft_bigendian32_read(vm->arena + idx_address);
	*pos += 2;
	return (arg_val);
}

static int		cw_vm_op_or_helper(t_cw_vm *vm, int *arg_val, int *pos)
{
	int			i;
	int			index;

	i = -1;
	while (++i < 2)
		if (vm->inst.types[i] == T_REG)
		{
			if (cw_vm_is_reg(vm->arena[
					(vm->game.procs->pos + *pos) % CW_MEM_SIZE]) == FALSE)
				return (CW_FAILURE);
			index = vm->arena[(vm->game.procs->pos + *pos) % CW_MEM_SIZE] - 1;
			arg_val[i] = vm->game.procs->regs[index];
			(*pos)++;
		}
		else if (vm->inst.types[i] == T_DIR)
			arg_val[i] = cw_vm_op_or_dir(vm, pos);
		else if (vm->inst.types[i] == T_IND)
			arg_val[i] = cw_vm_op_or_ind(vm, pos);
	return (CW_SUCCESS);
}

static void		cw_vm_op_or_body(t_cw_vm *vm)
{
	int			pos;
	int			index;
	int			reg_value;
	int			arg_val[3];

	pos = 2;
	if (cw_vm_op_or_helper(vm, arg_val, &pos) == CW_SUCCESS)
		if (cw_vm_is_reg(vm->arena[(vm->game.procs->pos + pos) % CW_MEM_SIZE]))
		{
			reg_value = arg_val[0] | arg_val[1];
			index = vm->arena[(vm->game.procs->pos + pos) % CW_MEM_SIZE] - 1;
			vm->game.procs->regs[index] = reg_value;
			vm->game.procs->carry = (reg_value == 0) ? 1 : 0;
		}
}

/*
** This instruction applyes the bitwise OR operation to the 2 first and stores
** the result in the third
*/

void			cw_vm_op_or(t_cw_vm *vm)
{
	if (vm->inst.args_count >= 3 && vm->inst.types[2] == T_REG)
		cw_vm_op_or_body(vm);
	vm->game.procs->pos = (vm->game.procs->pos + 2
			+ cw_vm_add_pos(&vm->inst, 3, CW_DIR_SIZE_OR)) % CW_MEM_SIZE;
}
