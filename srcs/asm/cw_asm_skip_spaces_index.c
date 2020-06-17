/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_skip_spaces_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:37 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:22:38 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Return the first index that is not a space after index
*/

int				cw_asm_skip_spaces_index(t_cw_linst *linst, int index)
{
	while (ft_isblank(linst->raw[index]))
		index++;
	return (index);
}
