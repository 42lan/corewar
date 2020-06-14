/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:14:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/14 19:51:19 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void				cw_vm_op_lld_dir_exec(t_cw_game *game, t_cw_vm *vm)
{
	int				index;
	int32_t			arg1;

	arg1 = ft_bigendian32_read(vm->arena + ((game->procs->pos + 2) % CW_MEM_SIZE));
	index = vm->arena[(game->procs->pos + 6) % CW_MEM_SIZE];
	if (cw_vm_is_reg(index) == true)
	{
		game->procs->regs[index - 1] = arg1;
		game->procs->carry = (arg1 == 0) ? 1 : 0;
	}
}

void				cw_vm_op_lld_ind_exec(t_cw_game *game, t_cw_vm *vm)
{
	int				index;
	int16_t			arg1;
	int				value;
	int				idx_address;

	arg1 = ft_bigendian16_read(vm->arena + ((game->procs->pos + 2) % CW_MEM_SIZE));
	idx_address = (game->procs->pos + arg1) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	index = vm->arena[(game->procs->pos + 4) % CW_MEM_SIZE];
	if (cw_vm_is_reg(index) == true)
	{
		value = ft_bigendian32_read(vm->arena + idx_address);
		game->procs->regs[index - 1] = value;
		game->procs->carry = (value == 0) ? 1 : 0;
	}
}

void				cw_vm_op_lld(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count >= 2 && inst->types[0] != T_REG && inst->types[1] == T_REG)
	{
		if (inst->types[0] == T_DIR)
			cw_vm_op_lld_dir_exec(game, vm);
		else if (inst->types[0] == T_IND)
			cw_vm_op_lld_ind_exec(game, vm);
	}
	// opc + encoding byte + (T_DIR | T_IND) + T_REG
	// 7 T_DIR T_REG
	// 5 T_IND T_REG
	game->procs->pos = (game->procs->pos + 2 + cw_vm_add_pos(inst, 2, CW_DIR_SIZE_LLD)) % CW_MEM_SIZE;
	/* ft_printf("0x%02x 0x%02x 0x%02x\n", vm->arena[game->procs->pos-1], vm->arena[game->procs->pos], vm->arena[game->procs->pos + 1]); */
}
