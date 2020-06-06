/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parsing_number_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:38:37 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/06 13:10:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"

static void	cw_swap_number_player(t_cw_data *data, int i1, int i2)
{
	char	*tmp_str;
	int		tmp_nb;

	tmp_nb = data->assigned_nbr[i1];
	data->assigned_nbr[i1] = data->assigned_nbr[i2];
	data->assigned_nbr[i2] = tmp_nb;
	tmp_str = data->filename[i1];
	data->filename[i1] = data->filename[i2];
	data->filename[i2] = tmp_str;
}

static void	cw_sort_number_player(t_cw_data *data)
{
	int i;

	i = -1;
	while (++i < data->nbr_players)
		if (data->assigned_nbr[i] > 0 && data->assigned_nbr[i] <= data->nbr_players)
			cw_swap_number_player(data, i, data->assigned_nbr[i] - 1);
	i = -1;
	while (++i + 1 < data->nbr_players)
	{
		if (data->assigned_nbr[i] < 0 &&
		data->assigned_nbr[i] > data->assigned_nbr[i + 1])
		{
			cw_swap_number_player(data, i, i + 1);
			i = -1;
		}
	}
}

/*
** Sort player in order in stucture data depending on option
*/

void		cw_parsing_number_player(t_cw_data *data)
{
	int i;

	i = -1;
	while (++i + 1 < data->nbr_players)
	{
		if (data->assigned_nbr[i] > data->assigned_nbr[i + 1])
		{
			cw_swap_number_player(data, i, i + 1);
			i = -1;
		}
	}
	cw_sort_number_player(data);
}
