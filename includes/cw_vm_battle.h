/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_battle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:14:35 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/11 14:22:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_BATTLE_H
# define CW_VM_BATTLE_H

# include "libft.h"
# include "cw_vm.h"

# define CW_CYCLE_TO_DIE	1536
# define CW_CYCLE_DELTA		50
# define CW_REG_NUMBER		16
# define CW_NBR_LIVE		21
# define CW_MAX_CHECKS			10

# define CW_DIR_SIZE_LIVE	4
# define CW_DIR_SIZE_LD		4
# define CW_DIR_SIZE_ST		4
# define CW_DIR_SIZE_ADD	4
# define CW_DIR_SIZE_SUB	4
# define CW_DIR_SIZE_AND	4
# define CW_DIR_SIZE_OR		4
# define CW_DIR_SIZE_XOR	4
# define CW_DIR_SIZE_ZJMP	2
# define CW_DIR_SIZE_LDI	2
# define CW_DIR_SIZE_STI	2
# define CW_DIR_SIZE_FORK	2
# define CW_DIR_SIZE_LLD	4
# define CW_DIR_SIZE_LLDI	2
# define CW_DIR_SIZE_LFORK	2
# define CW_DIR_SIZE_AFF	4

typedef struct		s_cw_proc t_cw_proc;
typedef struct		s_cw_proc
{
	t_bool			carry;
	int				opc;
	int				last_live;
	int				wait_cycles;
	int				pos;
	int				jump;
	int				id;
	int				regs[CW_REG_NUMBER];
	t_cw_proc		*next;
}					t_cw_proc;

typedef struct		s_cw_battle
{
	int				last_alive;
	int				cycles_count;
	int				cycle_to_die;
	int				check_performed;
	unsigned long	count_last_live;
	int				cycle_opc[16];
	t_bool			byte_codage[16];
	t_cw_proc		*procs;
	t_cw_proc		*head;
}					t_cw_battle;

void	cw_vm_ini_battle(t_cw_battle *battle, t_cw_vm *vm);
void	cw_vm_start_game(t_cw_battle *battle, t_cw_vm *vm);
void	cw_vm_read_execute(t_cw_battle *battle, t_cw_vm *vm);
void	cw_vm_proc_dump(t_cw_proc *proc);

#endif
