/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:15:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/14 16:18:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void			cw_vm_op_lfork(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int			idx_address;
	int16_t		arg1;
	t_cw_proc	*new;

	(void)inst;
	arg1 = ft_bigendian16_read(vm->arena + ((game->procs->pos + 1) % CW_MEM_SIZE));
	idx_address = game->procs->pos + arg1;
	if (!(new = ft_memdup(game->procs, sizeof(t_cw_proc)))) //a verifier le tableau de registre
		exit(CW_ERROR_MALLOC_FAILED);
	// COPIER LE TABLEAU DES REGS[]
	new->pos = idx_address;
	new->next = game->head;
	game->head = new;
	// opc + T_DIR
	// 3
	game->procs->pos = (game->procs->pos + 1 + CW_DIR_SIZE_LFORK) % CW_MEM_SIZE;
	/* ft_printf("0x%02x 0x%02x 0x%02x\n", vm->arena[game->procs->pos-1], vm->arena[game->procs->pos], vm->arena[game->procs->pos + 1]); */
}
