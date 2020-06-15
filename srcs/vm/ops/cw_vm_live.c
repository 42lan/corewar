/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:59:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 05:51:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

/*
** This instruction indicates that the player is alive
*/

void			cw_vm_op_live(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	long	arg1;

	(void)inst;
	arg1 = ft_bigendian32_read(vm->arena + ((game->procs->pos + 1) % CW_MEM_SIZE));
	game->procs->last_live = 1;
	if (arg1 < 0 && (arg1 * -1) <= vm->data.nbr_players)
	{
		game->last_alive = (arg1 * - 1) - 1;
		game->count_last_live++;
	}
	game->procs->pos = (game->procs->pos + (1 + CW_DIR_SIZE_LIVE)) % CW_MEM_SIZE;
}
