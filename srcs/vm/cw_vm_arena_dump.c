/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_arena_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 12:41:56 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/12 21:14:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cw_vm_arena_dump(unsigned char *arena, unsigned int size)
{
	unsigned int	i;
	unsigned char	*pc;

	i = -1;
	pc = arena;
	while (++i < size)
	{
		if ((i % 64) == 0)
		{
			(i != 0) ? ft_putchar('\n') : 0;
			ft_printf("{bold}0x%06x:{}", i);
		}
		(i % 1 == 0) ? ft_putchar(' ') : 0;
		ft_printf("%02x", pc[i]);
	}
	while ((i % 64) != 0)
	{
		(i % 1 == 0) ? ft_putchar(' ') : 0;
		ft_printf("00", i++);
	}
	ft_putchar('\n');
}
