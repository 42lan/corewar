/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:48:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/04 18:48:57 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_PARSING_H
# define CW_VM_PARSING_H

/*
** Data struct create with parsing
**
** nbr_cycles = dump the memory in nbr_cycles
** number = number of the next players
*/

typedef struct		s_cw_data
{
	unsigned int	nbr_cycles;
	unsigned int	number;
}					t_cw_data;


#endif