/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_skip_alnums_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:25 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:22:29 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Return the first index that is not a space after index
*/

int				cw_asm_skip_alnums_index(t_cw_linst *linst, int index)
{
	while (ft_isalnum(linst->raw[index]))
		index++;
	return (index);
}
