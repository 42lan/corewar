/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 01:22:20 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/13 20:17:03 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void				cw_vm_op_ld_dir_exec(t_cw_game *game, t_cw_vm *vm)
{
	int				index;
	int32_t			arg1;

	arg1 = ft_bigendian32_read(vm->arena + game->procs->pos + 2);
	index = vm->arena[(game->procs->pos + 6) % CW_MEM_SIZE];
	if (cw_vm_is_reg(index) == true)
	{
		game->procs->regs[index - 1] = arg1;
		game->procs->carry = (arg1 == 0) ? 1 : 0;
	}
}

void				cw_vm_op_ld_ind_exec(t_cw_game *game, t_cw_vm *vm)
{
	int				index;
	int16_t			arg1;
	int				value;
	int				idx_address;

	arg1 = ft_bigendian16_read(vm->arena + game->procs->pos + 2);
	idx_address = (game->procs->pos + (arg1 % CW_IDX_MOD)) % CW_MEM_SIZE;
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

void	cw_vm_op_ld(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count == 2 && inst->types[0] != T_REG && inst->types[1] == T_REG)
	{
		if (inst->types[0] == T_DIR)
			cw_vm_op_ld_dir_exec(game, vm);
		else if (inst->types[0] == T_IND)
			cw_vm_op_ld_ind_exec(game, vm);
	}
	// opc + encoding byte + (T_DIR | T_IND) + T_REG
	// T_DIR 7, T_IND 5
	game->procs->pos = (game->procs->pos + (1 + 1 + ((inst->types[0] == T_DIR) ? CW_DIR_SIZE_LD : 2) + 1)) % CW_MEM_SIZE;
}
