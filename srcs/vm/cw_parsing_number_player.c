/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parsing_number_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:38:37 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/05 18:38:37 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"

static void	cw_swap_number_player(t_cw_data *data, int i1, int i2)
{
	char	*tmp_str;
	int		tmp_nb;

	tmp_nb = data->filenumber[i1];
	data->filenumber[i1] = data->filenumber[i2];
	data->filenumber[i2] = tmp_nb;
	tmp_str = data->filename[i1];
	data->filename[i1] = data->filename[i2];
	data->filename[i2] = tmp_str;
}

static void	cw_sort_number_player(t_cw_data *data)
{
	int i;

	i = -1;
	while (++i + 1 < data->number)
	{
		if (data->filenumber[i] > data->filenumber[i + 1])
		{
			cw_swap_number_player(data, i, i + 1);
			i = -1;
		}
	}
	i = -1;
	while (++i < data->number)
		if (data->filenumber[i] > 0 && data->filenumber[i] <= data->number)
			cw_swap_number_player(data, i, data->filenumber[i] - 1);
	i = -1;
	while (++i + 1 < data->number)
	{
		if (data->filenumber[i] < 0 &&
		data->filenumber[i] > data->filenumber[i + 1])
		{
			cw_swap_number_player(data, i, i + 1);
			i = -1;
		}
	}
}

void		cw_parsing_number_player(t_cw_data *data, t_cw_player *players)
{
	int i;

	i = -1;
	(void)players;
	(void)i;
	cw_sort_number_player(data);
	//while (++i < data->number)
	//	(players[i])->name = 
}
