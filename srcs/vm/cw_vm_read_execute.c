/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:41:22 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/16 04:42:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"
#include "cw_inst.h"
#include "cw_op.h"
#include "cw_operations.h"

/*
** cw_vm_read_execute() prepare instruction's structure and choose right
** function to be called
*/

void	cw_vm_read_execute(t_cw_vm *vm)
{
	cw_inst_fill(vm);
	g_op_table[vm->inst.opc - 1](vm);
}
