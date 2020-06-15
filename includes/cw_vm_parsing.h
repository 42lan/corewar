/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:48:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/06 11:52:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_PARSING_H
# define CW_VM_PARSING_H

# include "cw_vm.h"

/*
** Data struct create with parsing
**
** nbr_players	- number of players
** filename		- name of the filename
** assigned_nbr	- assigned ID number of players (default value is -1)
*/

typedef struct		s_cw_data
{
	int				nbr_players;
	char			*filename[CW_MAX_PLAYERS];
	int				assigned_nbr[CW_MAX_PLAYERS];
}					t_cw_data;


#endif
