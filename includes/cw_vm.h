/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 15:01:47 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/17 19:56:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cw_inst.h"
#ifndef CW_VM_H
# define CW_VM_H


# include <stdlib.h>
# include <stdint.h>
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

int					cw_vm_usage(void);

/*
** P A R S I N G
*/

int					cw_vm_parsing(int argc, char **argv, t_cw_vm *vm);
int					cw_vm_set_dump(t_cw_vm *vm, char **av);
int					cw_vm_is_valid_extension(const char *argv, const char *extension);
int					cw_vm_set_player(t_cw_vm *vm, int assigned_nbr, char *filename);
int					cw_vm_set_player_helper(t_cw_vm *vm, int ac, char **av, int *i);
int					cw_vm_read_player(t_cw_vm *vm);

/*
** G A M E   ( B A T T L E )
*/

int					cw_vm_game(t_cw_vm *vm);
int					cw_vm_ini_game(t_cw_vm *vm);
int					cw_vm_start_game(t_cw_vm *vm, t_cw_game *game, t_cw_proc **procs);
void				cw_vm_read_execute(t_cw_vm *vm);
int					cw_vm_add_pos(t_cw_inst *inst, int nbr_arg, int label_size);
void				cw_inst_fill(t_cw_vm *vm);
int					cw_vm_ini_arena(t_cw_vm *vm);
void				cw_vm_intro_players(t_cw_vm *vm);

/*
** B I G E N D I A N   R W
*/

int32_t				cw_vm_bigendian32_read(unsigned char *data32, int index);
void				cw_vm_bigendian32_write(unsigned char *data32, int index, int32_t int32);
int16_t				cw_vm_bigendian16_read(unsigned char *data16, int index);
void				cw_vm_bigendian16_write(unsigned char *data16, int index, int16_t int16);

/*
** P R O C E S S E S   ( C U R S O R S )
*/

t_cw_proc			*cw_vm_proc_create(int id, int pos);
void				cw_vm_procs_destroy(t_cw_proc *head);
int					cw_vm_proc_count(t_cw_proc *head);
void				cw_vm_proc_dump(t_cw_proc *proc);

/*
** P R E D I C A T O R S
*/

t_bool				cw_vm_is_reg(int reg);
t_bool				cw_vm_is_valid_op(int op);

/*
** D E B U G
*/
void				cw_vm_print_data(t_cw_data *data);

#endif
