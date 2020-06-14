/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:13:14 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/12 16:06:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_game.h"
#include "cw_vm.h"
#include "cw_champion.h"

void		cw_vm_game(t_cw_vm *vm)
{
	t_cw_game	game;

	cw_vm_ini_game(&game, vm);
	cw_vm_intro_players(vm);
	cw_vm_start_game(&game, vm);
}
