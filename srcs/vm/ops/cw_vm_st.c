/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:32:09 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 15:31:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

static void		cw_vm_op_st_ind_exec(t_cw_game *game, t_cw_vm *vm)
{
	int			reg_value;
	int 		reg_index;
	int16_t 	arg2;

	reg_index = vm->arena[(game->procs->pos + 2) % CW_MEM_SIZE];
	if (cw_vm_is_reg(reg_index) == TRUE)
	{
		reg_value = game->procs->regs[reg_index - 1];
		arg2 = ft_bigendian16_read(vm->arena
				+ ((game->procs->pos + 3) % CW_MEM_SIZE));
		arg2 = (game->procs->pos + (arg2 % CW_IDX_MOD)) % CW_MEM_SIZE;
		if (arg2 < 0)
			arg2 += CW_MEM_SIZE;
		ft_bigendian32_write(vm->arena + arg2, reg_value);
	}
}

/*
** This instruction stores the value of the first argument in the second
*/

void	cw_vm_op_st(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int		arg[2];

	if (inst->args_count >= 2 && inst->types[0] == T_REG
			&& inst->types[1] != T_DIR)
	{
		if (inst->types[1] == T_REG)
		{
			arg[0] = vm->arena[(game->procs->pos + 2) % CW_MEM_SIZE];
			arg[1] = vm->arena[(game->procs->pos + 3) % CW_MEM_SIZE];
			if (cw_vm_is_reg(arg[0]) == TRUE && cw_vm_is_reg(arg[1]) == TRUE)
				game->procs->regs[arg[1] - 1] = game->procs->regs[arg[0] - 1];
		}
		else if (inst->types[1] == T_IND)
			cw_vm_op_st_ind_exec(game, vm);
	}
	game->procs->pos = (game->procs->pos + 2
			+ cw_vm_add_pos(inst, 2, CW_DIR_SIZE_ST)) % CW_MEM_SIZE;
}
