/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:15:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 23:10:07 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_lfork(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int				i;
	int16_t			arg1;
	int				idx_address;
	int				multiplier;
	t_cw_proc	*new;

	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, CW_DIR_SIZE_LFORK - 1);
	(void)inst;
	while (++i < CW_DIR_SIZE_LFORK)
	{
		arg1 += multiplier * vm->arena[(battle->procs->pos + 1 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	idx_address = battle->procs->pos + arg1;
	if (!(new = ft_memdup(battle->procs, sizeof(t_cw_proc)))) //a verifier le tableau de registre
		exit(CW_ERROR_MALLOC_FAILED);
	new->pos = idx_address;
	new->next = battle->head;
	battle->head = new;
	battle->procs->pos = (battle->procs->pos + 3) % CW_MEM_SIZE;
}
