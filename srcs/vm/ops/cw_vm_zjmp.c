/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:31:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/13 20:53:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void		cw_vm_op_zjmp(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int 	i;
	int 	value;
	int 	pow;

	if (inst->args_count == 1 && inst->types[0] == T_DIR && game->procs->carry == 1)
	{
		i = -1;
		value = 0;
		pow = ft_pow(256, CW_DIR_SIZE_ZJMP - 1);
		while (++i < CW_DIR_SIZE_ZJMP)
		{
			value += pow * vm->arena[game->procs->pos + i + 1];
			pow /= 256;
		}
		value %= CW_IDX_MOD;
		game->procs->pos += value;
		if (game->procs->pos < 0)
			game->procs->pos += CW_MEM_SIZE;
		game->procs->pos += (CW_DIR_SIZE_ZJMP) % CW_MEM_SIZE;
	}
	else
		game->procs->pos += (1) % CW_MEM_SIZE;
}
