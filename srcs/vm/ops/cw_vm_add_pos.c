/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_add_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 02:02:18 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/14 02:12:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_op.h"
#include "cw_vm_game.h"

/*
** cw_vm_add_pos() computes and return how many bytes should be skipped
** according to type of argument and its label size
*/

int			cw_vm_add_pos(t_inst *inst, int nbr_arg, int label_size)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	while(++i < nbr_arg)
	{
		if (ints.types[i] == T_REG)
			pos += 1;
		else if (ints.type[i] == T_IND)
			pos += 2;
		else if (ints.type[i] == T_DIR)
			pos += label_size;
	}
	return (pos);
}
