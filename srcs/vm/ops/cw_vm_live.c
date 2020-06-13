/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:59:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/13 21:09:53 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void			cw_vm_op_live(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int			i;
	int			arg1;
	unsigned	mult;

	if (inst->args_count == 1 && inst->types[0] == T_DIR)
	{
		i = -1;
		arg1 = 0;
		mult = ft_pow(256, CW_DIR_SIZE_LIVE - 1);
		while (++i < CW_DIR_SIZE_LIVE)
		{
			arg1 += mult * vm->arena[(game->procs->pos + 1 + i) % CW_MEM_SIZE];
			mult /= 256;
		}
		game->procs->last_live = 1;
		if (arg1 < 0 && arg1 * -1 <= vm->players->number)
		{
			game->last_alive = arg1 * - 1;
			game->count_last_live++;
		}
		ft_printf("Player %d is alive.\n", arg1);
	}
	// opc + T_DIR
	// 5
	game->procs->pos += (1 + CW_DIR_SIZE_LIVE) % CW_MEM_SIZE;
}
