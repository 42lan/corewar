/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:38:41 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/04 14:38:41 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_PLAYER_H
# define CW_VM_PLAYER_H

# include cw_champion.h

/*
** Struct player
**
** pointer to struct champion and more information for the player
*/

typedef struct		s_cw_player{
	t_cw_champion	*champion;
	unsigned int	number;
}					t_cw_player;

#endif
