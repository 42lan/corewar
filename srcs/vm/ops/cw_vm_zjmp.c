/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:31:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 21:08:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

/*
** This instruction makes a jump at IND_SIZE index if the carry is set to 1
*/

void		cw_vm_op_zjmp(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int		value;

	(void)inst;
	if (game->procs->carry == 1)
	{
		value = ft_bigendian16_read(vm->arena + ((game->procs->pos + 1)
				% CW_MEM_SIZE));
		game->procs->pos = (game->procs->pos
				+ (value % CW_IDX_MOD)) % CW_MEM_SIZE;
		if (game->procs->pos < 0)
			game->procs->pos += CW_MEM_SIZE;
	}
	else
		game->procs->pos = (game->procs->pos + 1 + CW_DIR_SIZE_ZJMP)
			% CW_MEM_SIZE;
}
