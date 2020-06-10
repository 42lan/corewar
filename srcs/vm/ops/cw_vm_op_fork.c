/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:13:59 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 19:58:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_fork(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int			i;
	int16_t		arg1;
	int			idx_address;
	int			multiplier;

	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, CW_DIR_SIZE_FORK - 1);
	if (inst->args_count != 1 || inst->types[0] != T_DIR)
		ft_printf("ERROR\n");
	while (++i < CW_DIR_SIZE_FORK)
	{
		arg1 += multiplier * vm->arena[(battle->processus->position + 1 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	idx_address = arg1 % CW_IDX_MOD;
	// alloc
	battle->processus->position += 3 % CW_MEM_SIZE;
	exit(0);
}
