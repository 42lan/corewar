/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_nothing_at_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:06 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 20:08:02 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Check that there is nothing of interest in an linst at an index and after.
*/

int				cw_asm_nothing_at_end(t_cw_asm *state, t_cw_linst *linst,
										int index)
{
	(void)state;
	while (1)
	{
		if (linst->raw[index] == '\0')
			return (CW_SUCCESS);
		if (linst->raw[index] == CW_COMMENT_CHAR)
			return (CW_SUCCESS);
		if (linst->raw[index] == CW_COMMENT_CHAR2)
			return (CW_SUCCESS);
		if (!ft_isblank(linst->raw[index]))
			return (cw_asmr(CW_ASMR_UNEXPECTED, index, linst));
		index++;
	}
	return (cw_asmr(CW_ASMR_UNEXPECTED, index, linst));
}
