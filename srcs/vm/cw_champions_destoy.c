/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_champions_destoy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 18:05:07 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/07 18:07:01 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_player.h"

void	cw_champions_destroy(t_cw_player *players, int i)
{
	while (--i != -1)
		cw_champion_destroy(&players[i].champion);
}
