/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:38:41 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/06 10:41:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_PLAYER_H
# define CW_VM_PLAYER_H

# include <fcntl.h>
# include <unistd.h>
# include "cw_champion.h"
# include "cw_common.h"

/*
** Struct s_cw_player
**
** All information about player
** name		- player's name
** comment	- player's comment
** code_len	- player's executable code size
** code		- player's executable code
** number	- player's unique ID number
*/

typedef struct		s_cw_player
{
	t_cw_champion	*champion;
	unsigned int	number;
}					t_cw_player;

void	cw_parsing_number_player(t_cw_data *data);
int		cw_vm_valid_player(t_cw_data *data, t_cw_player *players);

#endif
