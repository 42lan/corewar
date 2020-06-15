/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:38:41 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 02:06:16 by amalsago         ###   ########.fr       */
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
** champion - pointer to champion struct
** number	- player's unique ID number
*/

typedef struct		s_cw_player
{
	t_cw_champion	*champion;
	int				number;
	int				init_pos;
}					t_cw_player;

int		cw_parsing_number_player(t_cw_data *data);
int		cw_vm_valid_player(t_cw_data *data, t_cw_player *players);
int		cw_vm_read_magic_number(int fd);
int		cw_vm_read_champion_name(int fd, t_cw_player *player);
int		cw_vm_read_champion_null(int fd, char *part);
int		cw_vm_read_exec_code_len(int fd, t_cw_player *player);
int		cw_vm_read_champion_comment(int fd, t_cw_player *player);
int		cw_vm_read_champion_exec_code(int fd, t_cw_player *player);

#endif
