/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asmr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:09:19 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/18 06:08:36 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Print a cursor at an index showing the location of the error.
*/

void		cw_asmr_cursor(int index, char *from)
{
	int		i;
	int		from_len;

	from_len = from ? ft_strlen(from) : 0;
	i = 0;
	while (i < index)
	{
		if (index < from_len && from[i] == '\t')
			write(2, "\t", 1);
		else
			write(2, " ", 1);
		i++;
	}
	ft_dprintf(2, "{purple}^{}\n");
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
		ft_dprintf(2, "{light yellow}Warning{}: ");
	cw_asmr_msg(error, linst);
	if (linst)
		ft_dprintf(2, "%s\n", linst->raw);
	if (index >= 0 && linst)
		cw_asmr_cursor(index, linst->raw);
	return (error);
}
