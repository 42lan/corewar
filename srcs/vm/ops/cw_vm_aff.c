/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:15:23 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/17 04:30:11 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_inst.h"

void		cw_vm_op_aff(t_cw_vm *vm)
{
	int		arg_val;
	int		index;
	char	reg_value;

	if (vm->inst.args_count >= 1 && vm->inst.types[0] == T_REG)
	{
		index = vm->arena[(vm->game.procs->pos + 2) % CW_MEM_SIZE];
		arg_val = vm->game.procs->regs[index - 1];
		reg_value = arg_val % 256;
		ft_printf("%c\n", reg_value);
	}
	vm->game.procs->pos = (vm->game.procs->pos + 2
		+ cw_vm_add_pos(&vm->inst, 1, CW_DIR_SIZE_AFF)) % CW_MEM_SIZE;
}
