/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_argend_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:21:19 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:21:21 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Return the first index that marks the end of an arg.
*/

int				cw_asm_argend_index(t_cw_linst *linst, int index)
{
	while (linst->raw[index])
	{
		if (linst->raw[index] == CW_SEP_CHAR || ft_isblank(linst->raw[index]))
			return (index);
		if (linst->raw[index] == CW_COMMENT_CHAR || linst->raw[index] == ';')
			return (index);
		index++;
	}
	return (index);
}
