/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_arena_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 12:41:56 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/07 12:42:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cw_vm_arena_dump(unsigned char *arena, unsigned int size)
{
	unsigned int	i;
	unsigned char	buff[65];
	unsigned char	*pc;

	i = -1;
	pc = arena;
	while (++i < size)
	{
		if ((i % 64) == 0)
		{
			(i != 0) ? ft_printf(" %s\n", buff) : 0;
			ft_printf("{bold}0x%06x:{}", i);
		}
		(i % 2 == 0) ? ft_printf(" ") : 0;
		ft_printf("%02x", pc[i]);
		buff[(i % 64) + 1] = '\0';
	}
	while ((i % 64) != 0)
	{
		(i % 2 == 0) ? ft_printf(" ") : 0;
		ft_printf("00", i++);
	}
	ft_printf("\n");
}
