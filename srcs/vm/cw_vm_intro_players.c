/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_intro_champions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 14:24:09 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/07 14:36:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"

void	cw_vm_intro_players(t_cw_vm *vm)
{ 
	int				i;
	t_cw_champion	*champion;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm->data.nbr_players)
	{
		champion = vm->players[i].champion;
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\")\n",
			i + 1, champion->code_len, champion->name, champion->comment);
	}
}
