/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:15:23 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/13 21:07:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void	cw_vm_op_aff(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int		arg1;
	int		index;
	char	reg_value;

	if (inst->args_count == 1 && inst->types[0] == T_REG)
	{
		index = vm->arena[game->procs->pos + 2] - 1;
		arg1 = game->procs->regs[index];
		reg_value = arg1 % 256;
		ft_printf("{bold}{red}%c{}\n", reg_value);
	}
	// opc + encoding byte + T_REG
	// 6
	// 2
	game->procs->pos += (1 + 1 + ((inst->types[0] == T_REG) ? 1 : 0)) % CW_MEM_SIZE;
}
