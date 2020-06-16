/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_add_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 02:02:18 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/16 04:42:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_op.h"
#include "cw_inst.h"

/*
** cw_vm_add_pos() computes and return how many bytes should be skipped
** according to type of argument and its label size
*/

int			cw_vm_add_pos(t_cw_inst *inst, int nbr_arg, int label_size)
{
	int		i;
	int		pos;

	i = -1;
	pos = 0;
	while (++i < nbr_arg)
	{
		if (inst->types[i] == T_REG)
			pos += 1;
		else if (inst->types[i] == T_IND)
			pos += 2;
		else if (inst->types[i] == T_DIR)
			pos += label_size;
	}
	return (pos);
}
