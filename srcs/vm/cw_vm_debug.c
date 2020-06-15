/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 04:55:55 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 05:04:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"

/*
** cw_vm_print_data() prints data structure on standard output
*/

void		cw_vm_print_data(t_cw_data *data)
{
	int		i;

	i = -1;
	ft_printf("Number of players   = %d\n", data->nbr_players);
	while (++i < data->nbr_players && data->filename[i])
	{
		ft_printf("Player %d:\n", i + 1);
		ft_printf(" assigned ID  = %d\n", data->assigned_nbr[i]);
		ft_printf(" filename     = %s\n", data->filename[i]);
	}
}
