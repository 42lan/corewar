/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 15:01:47 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/16 04:37:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cw_inst.h"
#ifndef CW_VM_H
# define CW_VM_H


# include <stdlib.h>
# include "cw_vm_macros.h"
# include "cw_errors.h"
# include "cw_vm_parsing.h"
# include "cw_vm_player.h"

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

typedef struct		s_cw_vm
{
	t_cw_data		data;
	int				dump;
	t_cw_player		players[CW_MAX_PLAYERS];
	unsigned char	arena[CW_MEM_SIZE + 1];
	t_cw_game		game;
	t_cw_inst		inst;
}					t_cw_vm;

t_bool				cw_vm_is_reg(int reg);
t_bool				cw_vm_is_valid_op(int op);
void				cw_vm_usage(void);
int					cw_vm_parsing(int argc, char **argv, t_cw_vm *vm);
int					cw_vm_get_data(char **argv);
int					cw_vm_get_player(t_cw_vm *vm, char *filename);
int					cw_vm_is_valid_extension(const char *argv,
						const char *extension);
void				cw_vm_print_data(t_cw_data *data);
int					cw_vm_read_player(t_cw_vm *vm);
int					cw_vm_check_nbr_players(t_cw_vm *vm);
int					cw_vm_ini_arena(t_cw_vm *vm);
void				cw_vm_intro_players(t_cw_vm *vm);
int					cw_vm_game(t_cw_vm *vm);
void				cw_vm_print_data(t_cw_data *data);
int					cw_vm_set_player(t_cw_vm *vm, int assigned_nbr, char *filename);
int					cw_vm_set_player_helper(t_cw_vm *vm, int ac, char **av, int *i);
int					cw_vm_check_nbr_players(t_cw_vm *vm);
int					cw_vm_set_dump(t_cw_vm *vm, char **av, int *i);

int					cw_vm_ini_game(t_cw_vm *vm);
int					cw_vm_start_game(t_cw_vm *vm, t_cw_game *game);
void				cw_vm_read_execute(t_cw_vm *vm);
void				cw_vm_proc_dump(t_cw_proc *proc);
int					cw_vm_add_pos(t_cw_inst *inst, int nbr_arg, int label_size);
void				cw_inst_fill(t_cw_vm *vm);

#endif
