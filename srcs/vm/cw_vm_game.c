/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:13:14 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 20:23:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_game.h"
#include "cw_vm.h"
#include "cw_champion.h"

int				cw_vm_game(t_cw_vm *vm)
{
	int			ret;
	t_cw_game	game;

	if ((ret = cw_vm_ini_arena(vm)) != CW_SUCCESS)
		return (ret);
	if ((ret = cw_vm_ini_game(&game, vm)) != CW_SUCCESS)
		return (ret);
	cw_vm_intro_players(vm);
	if ((ret = cw_vm_start_game(&game, vm)) != CW_LAST_PROC)
		return (ret);
	return (CW_SUCCESS);
}
