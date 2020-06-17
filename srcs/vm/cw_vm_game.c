/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:13:14 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/17 05:14:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"
#include "cw_champion.h"

int				cw_vm_game(t_cw_vm *vm)
{
	int			ret;

	if ((ret = cw_vm_ini_arena(vm)) != CW_SUCCESS)
		return (ret);
	if ((ret = cw_vm_ini_game(vm)) != CW_SUCCESS)
		return (ret);
	cw_vm_intro_players(vm);
	if ((ret = cw_vm_start_game(vm, &vm->game)) != CW_SUCCESS)
		return (ret);
	return (CW_SUCCESS);
}
