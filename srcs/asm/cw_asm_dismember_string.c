/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_dismember_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:21:39 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 20:11:37 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Takes a string sourounded by quotes.
** The string is the last thing of interest on the line.
** Remove the sourounding quotes and replace them with '\0'.
** Return errors on issues.
*/

int		cw_asm_dismember_string(t_cw_asm *state, t_cw_linst *linst, int index)
{
	int		rst;

	if (linst->raw[index] == '\"')
		index++;
	else
		return (cw_asmr(CW_ASMR_STRING_INVALID, index, linst));
	while (linst->raw[index] != '\0' && linst->raw[index] != '\"')
		index++;
	if (linst->raw[index] == '\"')
		index++;
	else
		return (cw_asmr(CW_ASMR_STRING_INVALID, index, linst));
	if ((rst = cw_asm_nothing_at_end(state, linst, index)) < 0)
		return (rst);
	linst->raw[0] = '\0';
	linst->raw[index - 1] = '\0';
	return (CW_SUCCESS);
}
