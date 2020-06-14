/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:31:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/14 15:29:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void		cw_vm_op_zjmp(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int 	value;

	(void)inst;
	if (game->procs->carry == 0)
	{
		value = ft_bigendian16_read(vm->arena + ((game->procs->pos + 1)
				% CW_MEM_SIZE));
		if ((game->procs->pos = (game->procs->pos + value) % CW_IDX_MOD) < 0)
			game->procs->pos += CW_MEM_SIZE;
	}
	else
		game->procs->pos = (game->procs->pos + 1 + CW_DIR_SIZE_ZJMP)
			% CW_MEM_SIZE;
}
