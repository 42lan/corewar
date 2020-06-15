/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 01:22:20 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 20:51:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

static void		cw_vm_op_ld_dir_exec(t_cw_game *game, t_cw_vm *vm)
{
	int			index;
	int32_t		arg1;

	arg1 = ft_bigendian32_read(vm->arena
			+ ((game->procs->pos + 2) % CW_MEM_SIZE));
	index = vm->arena[(game->procs->pos + 6) % CW_MEM_SIZE];
	if (cw_vm_is_reg(index) == TRUE)
	{
		game->procs->regs[index - 1] = arg1;
		game->procs->carry = (arg1 == 0) ? 1 : 0;
	}
}

static void		cw_vm_op_ld_ind_exec(t_cw_game *game, t_cw_vm *vm)
{
	int			index;
	int			value;
	int			idx_address;
	int16_t		arg1;

	arg1 = ft_bigendian16_read(vm->arena
			+ ((game->procs->pos + 2) % CW_MEM_SIZE));
	idx_address = (game->procs->pos + (arg1 % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	index = vm->arena[(game->procs->pos + 4) % CW_MEM_SIZE];
	if (cw_vm_is_reg(index) == TRUE)
	{
		value = ft_bigendian32_read(vm->arena + idx_address);
		game->procs->regs[index - 1] = value;
		game->procs->carry = (value == 0) ? 1 : 0;
	}
}

/*
** This instruction loads the value of the first parameter in the register
*/

void			cw_vm_op_ld(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count >= 2 && inst->types[0] != T_REG
		&& inst->types[1] == T_REG)
	{
		if (inst->types[0] == T_DIR)
			cw_vm_op_ld_dir_exec(game, vm);
		else if (inst->types[0] == T_IND)
			cw_vm_op_ld_ind_exec(game, vm);
	}
	game->procs->pos = (game->procs->pos + 2
		+ cw_vm_add_pos(inst, 2, CW_DIR_SIZE_LD)) % CW_MEM_SIZE;
}
