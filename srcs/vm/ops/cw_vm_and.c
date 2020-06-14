/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:15:08 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/13 21:08:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

int		cw_vm_op_and_dir(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int total;

	total = ft_bigendian32_read(vm->arena + ((game->procs->pos + pos) % CW_MEM_SIZE));
	return (total);
}

int		cw_vm_op_and_ind(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int16_t			arg;
	int				total;
	int				idx_address;

	arg = ft_bigendian16_read(vm->arena + ((game->procs->pos + pos) % CW_MEM_SIZE));
	idx_address = (game->procs->pos + (arg % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	total = ft_bigendian32_read(vm->arena + idx_address);
	return (total);
}

void	cw_vm_op_and_body(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int i;
	int	arg[3];
	int	pos;
	int reg_value;

	i = -1;
	pos = 2;
	reg_value = 0;
	while (++i < 2)
	{
		if (inst->types[i] == T_REG)
		{
			if (cw_vm_is_reg(vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE]) == false)
				return ;
			arg[i] = game->procs->regs[(vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE]) - 1];
			pos++;
		}
		else if (inst->types[i] == T_DIR)
		{
			arg[i] = cw_vm_op_and_dir(game, vm, pos);
			pos += CW_DIR_SIZE_AND;
		}
		else if (inst->types[i] == T_IND)
		{
			arg[i] = cw_vm_op_and_ind(game, vm, pos);
			pos += 2;
		}
	}
	if (cw_vm_is_reg(vm->arena[(game->procs->pos + pos) %CW_MEM_SIZE]) == true)
	{
		reg_value = arg[0] & arg[1];
		game->procs->regs[vm->arena[(game->procs->pos + pos) %CW_MEM_SIZE] - 1] = reg_value;
		game->procs->carry = (reg_value == 0) ? 1 : 0;
	}
}

void	cw_vm_op_and(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count >= 3 && inst->types[2] == T_REG)
		cw_vm_op_and_body(inst, game, vm);
	// opc + encoding byte + (T_REG | T_DIR | T_IND) + (T_REG | T_DIR | T_IND) + T_REG
	//  5 T_REG T_REG
	//  8 T_REG T_DIR
	//  6 T_REG T_IND
	//  8 T_DIR T_REG
	// 11 T_DIR T_DIR
	//  9 T_DIR T_IND
	//  6 T_IND T_REG
	//  9 T_IND T_DIR
	//  7 T_IND T_IND
	game->procs->pos = (game->procs->pos + 2 + cw_vm_add_pos(inst, 3, CW_DIR_SIZE_AND)) % CW_MEM_SIZE;
	/* ft_printf("0x%02x 0x%02x 0x%02x\n", vm->arena[game->procs->pos-1], vm->arena[game->procs->pos], vm->arena[game->procs->pos + 1]); */
}
