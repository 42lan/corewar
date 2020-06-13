/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:04:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/13 19:03:44 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void	cw_vm_op_add(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int		arg[3];

	if (inst->args_count != 3 || inst->types[0] != T_REG || inst->types[1] != T_REG || inst->types[2] != T_REG)
	{
		ft_printf("ERROR inst\n");
	}
	arg[0] = game->procs->regs[vm->arena[(game->procs->pos + 2) % CW_MEM_SIZE] - 1];
	arg[1] = game->procs->regs[vm->arena[(game->procs->pos + 3) % CW_MEM_SIZE] - 1];
	arg[2] = arg[0] + arg[1];
	game->procs->regs[vm->arena[(game->procs->pos + 4) % CW_MEM_SIZE] - 1] = arg[2];
	game->procs->carry = (arg[2] == 0) ? 1 : 0;
	game->procs->pos = (game->procs->pos + 5) % CW_MEM_SIZE;
}
