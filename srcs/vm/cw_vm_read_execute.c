/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:41:22 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/08 23:37:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"
#include "cw_vm_battle.h"
#include "cw_inst.h"
#include "cw_op.h"

void	cw_vm_read_execute(t_cw_battle *battle, t_cw_vm *vm)
{
	t_cw_inst	inst;

	cw_inst_fill(&inst, vm, battle);
	cw_inst_dump(&inst);
	exit(0);
	//if (battle->byte_codage[battle->processus->op_code - 1] == 1)
		//var = read op_codagee;
	//else
	//	var = intruction(var)
}
