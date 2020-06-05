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

# include "cw_champion.h"

/*
** Struct player
**
** All information of player
*/

typedef struct		s_cw_player{
	char			*name;
	char			*comment;
	unsigned int	code_len;
	unsigned char	*code;
	unsigned int	number;
}					t_cw_player;

void	cw_parsing_number_player(t_cw_data *data, t_cw_player *players);

#endif
