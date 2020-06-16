/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:12:31 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/16 02:44:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_inst.h"

static int		cw_vm_op_ldi_dir(t_cw_vm *vm, int *pos)
{
	int			arg_pos;
	int			arg_val;

	arg_pos = (vm->game.procs->pos + *pos) % CW_MEM_SIZE;
	arg_val = ft_bigendian16_read(vm->arena + arg_pos);
	*pos += CW_DIR_SIZE_LDI;
	return (arg_val);
}

static int		cw_vm_op_ldi_ind(t_cw_vm *vm, int *pos)
{
	int16_t		arg_val;
	int			arg_pos;
	int			ind_val;
	int			idx_address;

	arg_pos = (vm->game.procs->pos + *pos) % CW_MEM_SIZE;
	arg_val = ft_bigendian16_read(vm->arena + arg_pos);
	idx_address = (vm->game.procs->pos + (arg_val % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	ind_val = ft_bigendian32_read(vm->arena + idx_address);
	*pos += 2;
	return (ind_val);
}

static int		cw_vm_op_ldi_helper(t_cw_vm *vm, int *arg_val, int *pos)
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
			index = vm->arena[(vm->game.procs->pos + *pos) % CW_MEM_SIZE];
			arg_val[i] = vm->game.procs->regs[index - 1];
			(*pos)++;
		}
		else if (vm->inst.types[i] == T_DIR)
			arg_val[i] = cw_vm_op_ldi_dir(vm, pos);
		else if (vm->inst.types[i] == T_IND)
			arg_val[i] = cw_vm_op_ldi_ind(vm, pos);
	return (CW_SUCCESS);
}

static void		cw_vm_op_ldi_body(t_cw_vm *vm)
{
	int			pos;
	int			arg_val[3];

	pos = 2;
	if (cw_vm_op_ldi_helper(vm, arg_val, &pos) == CW_SUCCESS)
	{
		arg_val[0] = (vm->game.procs->pos
				+ ((arg_val[0] + arg_val[1]) % CW_IDX_MOD)) % CW_MEM_SIZE;
		if (arg_val[0] < 0)
			arg_val[0] += CW_MEM_SIZE;
		arg_val[2] = vm->arena[(vm->game.procs->pos + pos) % CW_MEM_SIZE];
		if (cw_vm_is_reg(arg_val[2]))
			vm->game.procs->regs[arg_val[2] - 1]
				= ft_bigendian32_read(vm->arena + pos);
	}
}

/*
** This operation saves a value into the registry that was passed
** as third argument
*/

void			cw_vm_op_ldi(t_cw_vm *vm)
{
	if (vm->inst.args_count >= 3
		&& vm->inst.types[1] != T_IND && vm->inst.types[2] == T_REG)
		cw_vm_op_ldi_body(vm);
	vm->game.procs->pos = (vm->game.procs->pos + 2
			+ cw_vm_add_pos(&vm->inst, 3, CW_DIR_SIZE_LDI)) % CW_MEM_SIZE;
}
