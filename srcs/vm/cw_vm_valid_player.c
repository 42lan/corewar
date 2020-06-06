/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_valid_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:33:02 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/06 15:33:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"

int		cw_vm_read_magic_number(t_cw_data *data, t_cw_player *players, int number)
{
	open(data->filename[number], O_RDONLY);
}

int		cw_vm_valid_player(t_cw_data *data, t_cw_player *players)
{
	int i;

	i = -1;
	while (++i < data->nbr_players)
	{
		cw_vm_read_magic_number();
	}
}