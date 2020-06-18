/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:21:43 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/18 07:55:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cw_asm.h"

/*
** Print an non-asmr asm error code and return the same.
*/

int			cw_asm_error(int code)
{
	if (code == 0)
		return (code);
	else if (code == CW_ASM_ERROR_UNKNOWN_OPTION)
		ft_dprintf(2, "Unknown option.\n");
	else if (code == CW_ASM_ERROR_MALFORMED_FILE)
	{
		ft_dprintf(2, "What are you trying to do? ");
		ft_dprintf(2, "Please provide a valid champion source.\n");
	}
	else if (ft_abs(code) < CW_ASMR_MIN)
		ft_dprintf(2, "Exiting with code %d!\n", ft_abs(code));
	return (code);
}
