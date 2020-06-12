/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_is_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:20:47 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/12 15:11:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	cw_vm_is_valid_op(int op)
{
	if (op < 17	&& op > 0)
		return (true);
	return (false);
}

t_bool	cw_vm_is_reg(int reg)
{
	if (reg < 1 || reg > 16)
		return (false);
	return (true);
}