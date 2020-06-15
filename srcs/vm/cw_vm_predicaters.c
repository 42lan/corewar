/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_predicaters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:20:47 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/13 22:30:08 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"

t_bool	cw_vm_is_valid_op(int op)
{
	if (op < 17	&& op > 0)
		return (TRUE);
	return (FALSE);
}

t_bool	cw_vm_is_reg(int reg)
{
	if (reg < 1 || reg > CW_REG_NUMBER)
		return (FALSE);
	return (TRUE);
}
