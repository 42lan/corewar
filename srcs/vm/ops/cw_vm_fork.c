/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:13:59 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 16:47:34 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

/*
** This operation creates an identical copy of the process and places it
** to the position (Argument1 % IDX_MOD) + position of parent cursor
*/

void			cw_vm_op_fork(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int			idx_address;
	int16_t		arg1;
	t_cw_proc	*new;

	(void)inst;
	arg1 = ft_bigendian16_read(vm->arena
			+ ((game->procs->pos + 1) % CW_MEM_SIZE));
	idx_address = (game->procs->pos + (arg1 % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	if (!(new = ft_memdup(game->procs, sizeof(t_cw_proc)))) //a verifier le tableau de registre
	{
		ft_printf("{red}New processus can't be created for player %d\n{}",
		game->procs->id);
		return ;
	}
	// COPIER LE TABLEAU DE REGS[]
	new->pos = idx_address;
	new->next = game->head;
	game->head = new;
	game->procs->pos = (game->procs->pos + 1 + CW_DIR_SIZE_FORK) % CW_MEM_SIZE;
}
