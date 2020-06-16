/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:13:22 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/16 02:48:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

static int		cw_vm_op_sti_dir(t_cw_vm *vm, int *pos)
{
	int			arg_pos;
	int			arg_val;

	arg_pos = (vm->game.procs->pos + *pos) % CW_MEM_SIZE;
	arg_val = ft_bigendian16_read(vm->arena + arg_pos);
	*pos += CW_DIR_SIZE_STI;
	return (arg_val);
}

static int		cw_vm_op_sti_ind(t_cw_vm *vm, int *pos)
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

static int		cw_vm_op_sti_helper(t_cw_vm *vm, int *arg_val, int *pos)
{
	int			i;
	int			index;

	i = 0;
	while (++i < 3)
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
			arg_val[i] = cw_vm_op_sti_dir(vm, pos);
		else if (vm->inst.types[i] == T_IND)
			arg_val[i] = cw_vm_op_sti_ind(vm, pos);
	return (CW_SUCCESS);
}

static void		cw_vm_op_sti_body(t_cw_vm *vm)
{
	int			pos;
	int			idx_address;
	int			reg_value;
	int			arg_val[3];

	pos = 3;
	if (cw_vm_op_sti_helper(vm, arg_val, &pos) == CW_SUCCESS)
	{
		idx_address = (vm->game.procs->pos
				+ (arg_val[1] + arg_val[2]) % CW_IDX_MOD) % CW_MEM_SIZE;
		if (idx_address < 0)
			idx_address += CW_MEM_SIZE;
		arg_val[0] = vm->arena[vm->game.procs->pos + 2];
		if (cw_vm_is_reg(arg_val[0]))
		{
			reg_value = vm->game.procs->regs[arg_val[0] - 1];
			ft_bigendian32_write(vm->arena + idx_address, reg_value);
		}
	}
}

/*
** This operation writes the value from the registry that was passed
** as first argument
*/

void			cw_vm_op_sti(t_cw_vm *vm)
{
	if (vm->inst.args_count >= 3
		&& vm->inst.types[0] == T_REG && vm->inst.types[2] != T_IND)
		cw_vm_op_sti_body(vm);
	vm->game.procs->pos = (vm->game.procs->pos + 2
		+ cw_vm_add_pos(&vm->inst, 3, CW_DIR_SIZE_STI)) % CW_MEM_SIZE;
}
