/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:59:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/09 18:10:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_operations.h"

void	cw_vm_op_live(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int			i;
	int			arg1;
	unsigned	multiplier;

	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, 3);
	if (inst->args_count != 1 || inst->types[0] != T_DIR)
		ft_printf("ERROR\n");
	while (++i < CW_DIR_SIZE_LIVE)
	{
		arg1 += multiplier * vm->arena[battle->processus->position + 2 + i];
		multiplier /= 256;
	}
	ft_printf(">>%ld\n", arg1);
}
