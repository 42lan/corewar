/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_battle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:14:35 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 15:14:35 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_BATTLE_H
# define CW_VM_BATTLE_H

# include "libft.h"
# include "cw_vm.h"

# define CW_CYCLE_TO_DIE	1536
# define CW_REG_NUMBER		16

typedef struct	s_cw_processus
{
	t_bool	carry;
	int						op_code;
	int						last_live;
	int						wait_cycles;
	int						position;
	int						jump;
	int						id;
	int						registries[CW_REG_NUMBER];
	struct s_cw_processus	*next;
}				t_cw_processus;

typedef struct	s_cw_battle{
	int				last_alive;
	int				cycles_count;
	int				cycle_to_die;
	int				check_performed;
	int				count_last_live;
	t_cw_processus	*processus;
}				t_cw_battle;


void	cw_vm_ini_battle(t_cw_battle *battle, t_cw_vm *vm);

#endif