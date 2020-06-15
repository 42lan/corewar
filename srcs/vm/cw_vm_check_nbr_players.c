/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_check_nbr_players.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 05:00:07 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 05:03:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_errors.h"

/*
** cw_vm_check_nbr_players() checks if there is at least one player provided,
** otherwise it teminate program
*/

int		cw_vm_check_nbr_players(t_cw_vm *vm)
{
	if (vm->data.nbr_players == 0)
	{
		ft_dprintf(2, "{red}No players provided\n{}");
		return (CW_VM_NO_PLAYERS);
	}
	return (CW_SUCCESS);
}
