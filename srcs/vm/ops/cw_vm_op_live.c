/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:59:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/09 19:41:53 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"

void	cw_vm_op_live(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	int			i;
	int			arg1;
	unsigned	multiplier;

	i = -1;
	arg1 = 0;
	multiplier = ft_pow(256, CW_DIR_SIZE_LD - 1);
	(void)inst;
	while (++i < CW_DIR_SIZE_LIVE)
	{
		arg1 += multiplier * vm->arena[(battle->processus->position + 2 + i) % CW_MEM_SIZE];
		multiplier /= 256;
	}
	ft_printf(">>%ld\n", arg1);
}
