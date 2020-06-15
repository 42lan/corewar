/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:14:35 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 05:25:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_GAME_H
# define CW_VM_GAME_H

# include "libft.h"
# include "cw_vm.h"

# define CW_NOT_LAST_PROC		0
# define CW_LAST_PROC			1
# define CW_CYCLE_TO_DIE		1536
# define CW_CYCLE_DELTA			50
# define CW_REG_NUMBER			16
# define CW_NBR_LIVE			21
# define CW_MAX_CHECKS			10
# define CW_VM_DUMP				471

# define CW_DIR_SIZE_LIVE		4
# define CW_DIR_SIZE_LD			4
# define CW_DIR_SIZE_ST			4
# define CW_DIR_SIZE_ADD		4
# define CW_DIR_SIZE_SUB		4
# define CW_DIR_SIZE_AND		4
# define CW_DIR_SIZE_OR			4
# define CW_DIR_SIZE_XOR		4
# define CW_DIR_SIZE_ZJMP		2
# define CW_DIR_SIZE_LDI		2
# define CW_DIR_SIZE_STI		2
# define CW_DIR_SIZE_FORK		2
# define CW_DIR_SIZE_LLD		4
# define CW_DIR_SIZE_LLDI		2
# define CW_DIR_SIZE_LFORK		2
# define CW_DIR_SIZE_AFF		4

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

typedef struct		s_cw_game
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
}					t_cw_game;

# include "cw_inst.h"

int		cw_vm_ini_game(t_cw_game *game, t_cw_vm *vm);
int		cw_vm_start_game(t_cw_game *game, t_cw_vm *vm);
void	cw_vm_read_execute(t_cw_game *game, t_cw_vm *vm);
void	cw_vm_proc_dump(t_cw_proc *proc);
int		cw_vm_add_pos(t_cw_inst *inst, int nbr_arg, int label_size);

#endif
