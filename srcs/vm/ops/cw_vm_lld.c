/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:14:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/13 21:03:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void				cw_vm_op_lld_dir_exec(t_cw_game *game, t_cw_vm *vm)
{
	int				i;
	int32_t			arg1;
	int				index;
	unsigned int	mult;

	i = -1;
	arg1 = 0;
	mult = ft_pow(256, CW_DIR_SIZE_LLD - 1);
	while (++i < CW_DIR_SIZE_LLD)
	{
		arg1 += mult * vm->arena[(game->procs->pos + 2 + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	index = vm->arena[(game->procs->pos + 2 + i) % CW_MEM_SIZE] - 1;
	(cw_vm_is_reg(index) == false) ? ft_printf("ERROR\n") : 0;
	game->procs->regs[index] = arg1;
}

void				cw_vm_op_lld_ind_exec(t_cw_game *game, t_cw_vm *vm)
{
	int				i;
	int16_t			arg1;
	unsigned int	mult;
	int				to_address;
	int				index;

	i = -1;
	arg1 = 0;
	mult = 256;
	while (++i < 2)
	{
		arg1 += mult * vm->arena[(game->procs->pos + 2 + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	to_address = (game->procs->pos + arg1) % CW_MEM_SIZE;
	(to_address < 0) ? to_address += CW_MEM_SIZE : 0;
	i = -1;
	arg1 = 0;
	mult = ft_pow(256, 3);
	while (++i < 4)
	{
		arg1 += mult * vm->arena[(to_address + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	index = vm->arena[(game->procs->pos + 2 + i) % CW_MEM_SIZE];
	game->procs->regs[index - 1] = arg1;
	game->procs->carry = (arg1 == 0) ? 1 : 0;
}

void				cw_vm_op_lld(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count == 2 && inst->types[0] != T_REG && inst->types[1] == T_REG)
	{
		if (inst->types[0] == T_DIR)
			cw_vm_op_lld_dir_exec(game, vm);
		else if (inst->types[0] == T_IND)
			cw_vm_op_lld_ind_exec(game, vm);
	}
	// opc + encoding byte + (T_DIR | T_IND) + T_REG
	// 7 T_DIR T_REG
	// 5 T_IND T_REG
	game->procs->pos += (1 + 1) % CW_MEM_SIZE;
	game->procs->pos += ((inst->types[0] == T_DIR) ? CW_DIR_SIZE_LLD : 2) % CW_MEM_SIZE;
	game->procs->pos += (1) % CW_MEM_SIZE;
	/* ft_printf("0x%02x 0x%02x 0x%02x\n", vm->arena[game->procs->pos-1], vm->arena[game->procs->pos], vm->arena[game->procs->pos + 1]); */
}
