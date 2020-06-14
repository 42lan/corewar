/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:13:59 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/14 16:05:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void			cw_vm_op_fork(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int			idx_address;
	int16_t		arg1;
	t_cw_proc	*new;

	(void)inst;
	arg1 = ft_bigendian16_read(vm->arena + ((game->procs->pos + 1) % CW_MEM_SIZE));
	idx_address = game->procs->pos + (arg1 % CW_IDX_MOD);
	if (!(new = ft_memdup(game->procs, sizeof(t_cw_proc)))) //a verifier le tableau de registre
		exit(CW_ERROR_MALLOC_FAILED);
	// COPIER LE TABLEAU DE REGS[]
	new->pos = idx_address;
	new->next = game->head;
	game->head = new;
	// opc + T_DIR
	// 3
	game->procs->pos = (game->procs->pos + 1 + CW_DIR_SIZE_FORK) % CW_MEM_SIZE;
	/* ft_printf("0x%02x 0x%02x 0x%02x\n", vm->arena[game->procs->pos-1], vm->arena[game->procs->pos], vm->arena[game->procs->pos + 1]); */
}
