/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:21:43 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:21:46 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print an asm error code and return the same.
*/

int			cw_asm_error(int code)
{
	if (code == 0)
		return (code);
	if (code < 0)
		ft_dprintf(2, "Error %d!\n", code);
	if (code > 0)
		ft_dprintf(2, "Error %d!\n", code);
	return (code);
}
