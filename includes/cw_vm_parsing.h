/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:48:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/05 01:29:01 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_PARSING_H
# define CW_VM_PARSING_H

# include "cw_vm.h"

/*
** Data struct create with parsing
**
** nbr_cycles	- dump the memory in nbr_cycles
** number		- number of the next players
** filename		- name of the filename
** filenumber	- id of players (-1 is a default value)
*/

typedef struct		s_cw_data
{
	unsigned int	nbr_cycles;
	unsigned int	number;
	char			filename[CW_MAX_PLAYERS][CW_FILENAME_MAX_LEN];
	int				filenumber[CW_MAX_PLAYERS];
}					t_cw_data;


#endif
