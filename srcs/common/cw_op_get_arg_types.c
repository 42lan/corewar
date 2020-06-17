/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_op_get_arg_types.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:24:02 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:24:03 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_op.h"

/*
** Parse the coding types from a coding byte.
** Output to an array of 3 coding types.
*/

void	cw_op_get_arg_types(t_cw_arg_type *out3, t_cw_coding_byte coding_byte)
{
	out3[0] = cw_op_get_arg_type((coding_byte >> 6) & 0x03);
	out3[1] = cw_op_get_arg_type((coding_byte >> 4) & 0x03);
	out3[2] = cw_op_get_arg_type((coding_byte >> 2) & 0x03);
}
