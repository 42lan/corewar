/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:31:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/17 01:50:59 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_inst.h"

/*
** This instruction makes a jump at IND_SIZE index if the carry is set to 1
*/

void		cw_vm_op_zjmp(t_cw_vm *vm)
{
	int		arg_val;
	int		arg_pos;
	int		new_pos;

	if (vm->game.procs->carry == 1)
	{
		arg_pos = (vm->game.procs->pos + 1) % CW_MEM_SIZE;
		arg_val = cw_vm_bigendian16_read(vm->arena, arg_pos);
		new_pos = (vm->game.procs->pos + (arg_val % CW_IDX_MOD)) % CW_MEM_SIZE;
		vm->game.procs->pos = new_pos;
		if (vm->game.procs->pos < 0)
			vm->game.procs->pos += CW_MEM_SIZE;
	}
	else
	{
		new_pos = (vm->game.procs->pos + 1 + CW_DIR_SIZE_ZJMP) % CW_MEM_SIZE;
		vm->game.procs->pos = new_pos;
	}
}
