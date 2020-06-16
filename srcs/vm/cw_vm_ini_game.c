/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ini_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:23:59 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 23:03:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm_game.h"

static t_cw_proc	*cw_vm_ini_proc(int id, int pos)
{
	t_cw_proc	*processus;

	if (!(processus = (t_cw_proc *)malloc(sizeof(t_cw_proc))))
		return (NULL);
	id++;
	processus->carry = FALSE;
	processus->opc = -1;
	processus->last_live = -1;
	processus->wait_cycles = 0;
	processus->pos = pos;
	processus->jump = -1;
	processus->id = id;
	ft_bzero(processus->regs, sizeof(int) * CW_REG_NUMBER);
	processus->regs[0] = id * -1;
	processus->next = NULL;
	return (processus);
}

static void			cw_vm_ini_cycle_opc(t_cw_game *game)
{
	game->cycle_opc[0] = 10;
	game->cycle_opc[1] = 5;
	game->cycle_opc[2] = 5;
	game->cycle_opc[3] = 10;
	game->cycle_opc[4] = 10;
	game->cycle_opc[5] = 6;
	game->cycle_opc[6] = 6;
	game->cycle_opc[7] = 6;
	game->cycle_opc[8] = 20;
	game->cycle_opc[9] = 25;
	game->cycle_opc[10] = 25;
	game->cycle_opc[11] = 800;
	game->cycle_opc[12] = 10;
	game->cycle_opc[13] = 50;
	game->cycle_opc[14] = 1000;
	game->cycle_opc[15] = 2;
}

static void			cw_vm_ini_byte_codage(t_cw_game *game)
{
	game->byte_codage[0] = 0;
	game->byte_codage[1] = 1;
	game->byte_codage[2] = 1;
	game->byte_codage[3] = 1;
	game->byte_codage[4] = 1;
	game->byte_codage[5] = 1;
	game->byte_codage[6] = 1;
	game->byte_codage[7] = 1;
	game->byte_codage[8] = 0;
	game->byte_codage[9] = 1;
	game->byte_codage[10] = 1;
	game->byte_codage[11] = 0;
	game->byte_codage[12] = 1;
	game->byte_codage[13] = 1;
	game->byte_codage[14] = 0;
	game->byte_codage[15] = 1;
}

static void			cw_vm_ini_game_helper(t_cw_vm *vm)
{
	vm->game.last_alive = vm->data.nbr_players - 1;
	vm->game.cycles_count = 0;
	vm->game.cycle_to_die = CW_CYCLE_TO_DIE;
	vm->game.check_performed = 0;
	vm->game.count_last_live = 0;
	cw_vm_ini_cycle_opc(&vm->game);
	cw_vm_ini_byte_codage(&vm->game);
}

int					cw_vm_ini_game(t_cw_vm *vm)
{
	int			i;
	t_cw_proc	*ptr;

	i = vm->data.nbr_players - 1;
	cw_vm_ini_game_helper(vm);
	if (!(vm->game.procs = cw_vm_ini_proc(i, vm->players[i].init_pos)))
	{
		ft_dprintf(2, "{red}Error malloc failed{}\n");
		return (CW_ERROR_MALLOC_FAILED);
	}
	ptr = vm->game.procs;
	while (--i > -1)
	{
		if ((vm->game.procs->next
					= cw_vm_ini_proc(i, vm->players[i].init_pos)) == NULL)
		{
			ft_dprintf(2, "{red}Error malloc failed{}\n");
			return (CW_ERROR_MALLOC_FAILED);
		}
		vm->game.procs = vm->game.procs->next;
	}
	vm->game.procs = ptr;
	vm->game.head = ptr;
	return (CW_SUCCESS);
}
