/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:20:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/05 13:20:57 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"

/*
** Open file .cor and take all information to place in structure players
** Return error code when the file is not validate
*/

int			cw_vm_read_player(t_cw_data *data, t_cw_player *players)
{
	if (!(players = malloc(sizeof(t_cw_champion) * data->number)))
	{
		ft_printf("{red}MALLOC ERROR\n");
		exit (CW_ERROR_MALLOC_FAILED);
	}
	cw_parsing_number_player(data, players);
	return (CW_SUCCESS);
}