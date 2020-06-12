/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:15:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/12 16:15:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void			cw_vm_op_lfork(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int			i;
	int16_t		arg1;
	int			idx_address;
	int			mult;
	t_cw_proc	*new;

	i = -1;
	arg1 = 0;
	mult = ft_pow(256, CW_DIR_SIZE_LFORK - 1);
	(void)inst;
	while (++i < CW_DIR_SIZE_LFORK)
	{
		arg1 += mult * vm->arena[(game->procs->pos + 1 + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	idx_address = game->procs->pos + arg1;
	if (!(new = ft_memdup(game->procs, sizeof(t_cw_proc)))) //a verifier le tableau de registre
		exit(CW_ERROR_MALLOC_FAILED);
	new->pos = idx_address;
	new->next = game->head;
	game->head = new;
	game->procs->pos = (game->procs->pos + 3) % CW_MEM_SIZE;
}
