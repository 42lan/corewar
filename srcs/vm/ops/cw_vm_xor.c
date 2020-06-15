/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_xor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:11:41 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 21:08:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

static int		cw_vm_op_xor_dir(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int			total;

	total = ft_bigendian32_read(vm->arena
			+ ((game->procs->pos + pos) % CW_MEM_SIZE));
	return (total);
}

static int		cw_vm_op_xor_ind(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int			total;
	int			idx_address;
	int16_t		arg;

	arg = ft_bigendian16_read(vm->arena
			+ ((game->procs->pos + pos) % CW_MEM_SIZE));
	idx_address = (game->procs->pos + (arg % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	total = ft_bigendian32_read(vm->arena + idx_address);
	return (total);
}

static void		cw_vm_op_xor_body(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int			i;
	int			pos;
	int			reg_value;
	int			arg[3];

	i = -1;
	pos = 2;
	while (++i < 2)
		if (inst->types[i] == T_REG)
		{
			if (cw_vm_is_reg(vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE]) == FALSE)
				return ;
			arg[i] = game->procs->regs[(vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE]) - 1];
			pos++;
		}
		else if (inst->types[i] == T_DIR)
		{
			arg[i] = cw_vm_op_xor_dir(game, vm, pos);
			pos += CW_DIR_SIZE_XOR;
		}
		else if (inst->types[i] == T_IND)
		{
			arg[i] = cw_vm_op_xor_ind(game, vm, pos);
			pos += 2;
		}
	if (cw_vm_is_reg(vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE]) == TRUE)
	{
		reg_value = arg[0] ^ arg[1];
		game->procs->regs[vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE] - 1] = reg_value;
		game->procs->carry = (reg_value == 0) ? 1 : 0;
	}
}

/*
** This instruction applyes the bitwise XOR operation to the 2 first and stores
** the result in the third
*/

void			cw_vm_op_xor(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count >= 3 && inst->types[2] == T_REG)
		cw_vm_op_xor_body(inst, game, vm);
	game->procs->pos = (game->procs->pos + 2
			+ cw_vm_add_pos(inst, 3, CW_DIR_SIZE_XOR)) % CW_MEM_SIZE;
}
