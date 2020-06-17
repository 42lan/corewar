/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asmr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:09:19 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 20:22:05 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Print a cursor at an index showing the location of the error.
*/

void		cw_asmr_cursor(int index)
{
	int		i;

	if (index >= 0)
	{
		i = 0;
		while (i < index)
		{
			write(2, " ", 1);
			i++;
		}
		ft_dprintf(2, "{purple}^{}\n");
	}
}

/*
** Return an error after displaying it.
*/

int			cw_asmr(int error, int index, t_cw_linst *linst)
{
	if (error == CW_SUCCESS)
		return (0);
	if (error < 0)
		ft_dprintf(2, "{red}Error{}: ");
	else
		ft_dprintf(2, "{orange}Warning{}: ");
	cw_asmr_msg(error, linst);
	ft_dprintf(2, "%s\n", linst->raw);
	cw_asmr_cursor(index);
	ft_putchar('\n');
	return (error);
}
