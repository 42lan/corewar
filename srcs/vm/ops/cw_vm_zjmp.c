/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:31:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/11 14:44:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_zjmp(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int i;
	int value;
	int pow;

	i = -1;
	value = 0;
	pow = ft_pow(256, CW_DIR_SIZE_ZJMP - 1);
	(void)inst;
	if (battle->procs->carry == 0)
	{
		battle->procs->pos += CW_DIR_SIZE_ZJMP;
		return ;
	}
	while (++i < CW_DIR_SIZE_ZJMP)
	{
		value += pow * vm->arena[battle->procs->pos + i + 1];
		pow /= 256;
	}
	value %= CW_IDX_MOD;
	battle->procs->pos += value;
	if (battle->procs->pos < 0)
		battle->procs->pos += CW_MEM_SIZE;
}
