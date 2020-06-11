/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:41:22 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/09 13:30:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"
#include "cw_op.h"
#include "cw_operations.h"

void	cw_vm_read_execute(t_cw_battle *battle, t_cw_vm *vm)
{
	t_cw_inst	inst;

	cw_inst_fill(&inst, vm, battle);
	//cw_inst_dump(&inst);
	g_op_table[inst.opc - 1](&inst, battle, vm);
}
