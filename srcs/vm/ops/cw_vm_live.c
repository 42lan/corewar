/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:59:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/18 10:30:01 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_inst.h"

/*
** This instruction indicates that the player is alive
*/

void		cw_vm_live(t_cw_vm *vm)
{
	long	arg_val;
	int		arg_pos;
	int		new_pos;

	arg_pos = (vm->game.procs->pos + 1) % CW_MEM_SIZE;
	arg_val = cw_vm_bigendian32_read(vm->arena, arg_pos);
	vm->game.procs->last_live = 1;
	if (arg_val < 0 && (arg_val * -1) <= vm->data.nbr_players)
	{
		vm->game.last_alive = (arg_val * -1) - 1;
		vm->game.count_last_live++;
		if (vm->game.count_last_live == INT32_MAX)
			vm->game.count_last_live = CW_NBR_LIVE + 1;
	}
	new_pos = (vm->game.procs->pos + (1 + CW_DIR_SIZE_LIVE)) % CW_MEM_SIZE;
	vm->game.procs->pos = new_pos;
}
