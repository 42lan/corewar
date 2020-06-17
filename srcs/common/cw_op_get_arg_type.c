/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_op_get_arg_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:23:58 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:24:00 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_op.h"

/*
** Convert a coding code to a coding type.
*/

t_cw_arg_type			cw_op_get_arg_type(t_cw_coding_code code)
{
	static t_cw_arg_type types[3] = {CW_T_REG, CW_T_DIR, CW_T_IND};

	if (code > 3)
		return (0);
	return (types[(int)code]);
}
