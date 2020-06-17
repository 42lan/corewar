/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_skip_label_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:33 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:44:45 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Return the index of the char after the label in a linst.
*/

int				cw_asm_skip_label_index(t_cw_linst *linst)
{
	int		i;

	if (linst->label == NULL)
		return (0);
	i = 0;
	while (linst->raw[i] != CW_LABEL_CHAR)
		i++;
	return (i + 1);
}
