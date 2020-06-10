/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:13:59 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/10 22:08:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_fork(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int				i;
	int16_t			arg1;
	int				idx_address;
	int				multiplier;
	t_cw_processus	*new;

	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, CW_DIR_SIZE_FORK - 1);
	ft_printf("%d %d\n", inst->args_count, inst->types[0]);
	if (inst->args_count != 1 || inst->types[0] != T_DIR)
		ft_printf("ERROR\n");
	while (++i < CW_DIR_SIZE_FORK)
	{
		arg1 += multiplier * vm->arena[(battle->processus->position + 1 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	idx_address = battle->processus->position + arg1 % CW_IDX_MOD;
	if (!((new = ft_memdup(battle->processus, sizeof(t_cw_processus *)))))
		exit(CW_ERROR_MALLOC_FAILED);
	new->position = idx_address;
	new->carry = false;
	new->last_live = -1;
	new->wait_cycles = 0;
	battle->processus->position += 3 % CW_MEM_SIZE;
	exit(0);
}
