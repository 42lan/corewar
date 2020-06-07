/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:13:14 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 15:13:14 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"
#include "cw_vm_battle.h"
#include "cw_champion.h"

void		cw_vm_battle(t_cw_vm *vm)
{
	t_cw_battle	battle;

	ft_printf("{blue}pinponpinpon{}\n");
	cw_vm_ini_battle(&battle, vm);
	ft_printf("{blue}pinponpinpon{}\n");
	cw_vm_intro_players(vm);
}