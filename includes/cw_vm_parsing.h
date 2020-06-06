/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:48:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/06 10:39:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_PARSING_H
# define CW_VM_PARSING_H

# include "cw_vm.h"

/*
** Data struct create with parsing
**
** nbr_cycles	- dump the memory in nbr_cycles
** nbr_players	- number of players
** filename		- name of the filename
** filenumber	- id of players (-1 is a default value)
*/

typedef struct		s_cw_data
{
	int				nbr_cycles;
	int				nbr_players;
	char			*filename[CW_MAX_PLAYERS];
	int				filenumber[CW_MAX_PLAYERS];
}					t_cw_data;


#endif
