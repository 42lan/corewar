/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:20:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 01:35:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"

/*
** Open `.cor` file and take all information to fill player's structure
** Return error code when the file is not validate
*/

int			cw_vm_read_player(t_cw_data *data, t_cw_player *players)
{
	ft_printf("{yellow}-------------ENTER IN READ PLAYER-------------\n{}");
	if (!(players = malloc(sizeof(t_cw_champion) * data->nbr_players)))
	{
		ft_dprintf(2, "{red}MALLOC ERROR\n{}");
		exit(CW_ERROR_MALLOC_FAILED);
	}
	cw_parsing_number_player(data);
	cw_vm_valid_player(data, players);
	return (CW_SUCCESS);
}
