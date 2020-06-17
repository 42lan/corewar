/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_spaces_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:40 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:22:41 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Skip all non-space characters.
** Return the corresponding index in the linst raw string.
*/

int				cw_asm_spaces_index(t_cw_linst *linst, int index)
{
	while (linst->raw[index] && !ft_isblank(linst->raw[index]))
		index++;
	return (index);
}
