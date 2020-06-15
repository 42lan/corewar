/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:01:49 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 05:59:07 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

/*
** This instruction substracts the contents of the 2 first and stores the result
** in the third
*/

void		cw_vm_op_sub(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int		arg[3];
	int		regs[3];

	if (inst->args_count >= 3 && inst->types[0] == T_REG
			&& inst->types[1] == T_REG && inst->types[2] == T_REG)
	{
		regs[0] = vm->arena[(game->procs->pos + 2) % CW_MEM_SIZE];
		regs[1] = vm->arena[(game->procs->pos + 3) % CW_MEM_SIZE];
		regs[2] = vm->arena[(game->procs->pos + 4) % CW_MEM_SIZE];
		if (cw_vm_is_reg(regs[0]) && cw_vm_is_reg(regs[1])
				&& cw_vm_is_reg(regs[2]))
		{
			arg[0] = game->procs->regs[regs[0] - 1];
			arg[1] = game->procs->regs[regs[1] - 1];
			arg[2] = arg[0] - arg[1];
			game->procs->regs[regs[2] - 1] = arg[2];
			game->procs->carry = (arg[2] == 0) ? 1 : 0;
		}
	}
	game->procs->pos = (game->procs->pos + 2
			+ cw_vm_add_pos(inst, 3, CW_DIR_SIZE_SUB)) % CW_MEM_SIZE;
}
