/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_op_get_coding_byte.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:24:10 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:24:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_op.h"

/*
** Convert a coding type to a coding byte.
** "index" is the index of the op's argument.
** To create a full coding byte, you can call this function
** oce
*/

t_cw_coding_byte		cw_op_get_coding_byte(t_cw_arg_type type, int index)
{
	return (cw_op_get_coding_code(type) << index);
}
