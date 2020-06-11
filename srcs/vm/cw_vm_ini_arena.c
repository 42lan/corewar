/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ini_arena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 03:04:40 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/11 13:22:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"
#include "cw_vm_arena.h"

/*
** Verify if the space in arena is enough to place all player
*/

static void		cw_vm_verify_enough_space(t_cw_vm *vm)
{
	int			i;
	int			j;
	unsigned	total;
	unsigned	delta;

	i = -1;
	j = 0;
	total = 0;
	delta = (unsigned int)(CW_MEM_SIZE / vm->data.nbr_players);
	while (++i < vm->data.nbr_players)
		total += vm->players[i].champion->code_len;
	i = -1;
	while (j == 0 && ++i  < vm->data.nbr_players)
		if (vm->players[i].champion->code_len > delta)
			j = 1;
	if (total > CW_MEM_SIZE || (j == 1 && i < vm->data.nbr_players))
	{
		while (i != -1)
			cw_champion_destroy(&vm->players[i--].champion);
		exit(CW_VM_ERRO_NOT_ENOUGH_SPACE_IN_ARENA);
	}
}

/*
** Place champion's code on the Arena according to start pointer
*/

static void		cw_vm_place_code(t_cw_vm *vm, t_cw_champion *champion, int ptr)
{
	unsigned	i;

	i = -1;
	while (++i < champion->code_len)
		vm->arena[ptr + i] = champion->code[i];
}

/*
** Choose place where to place champion's code
*/

static void		cw_vm_place_player(t_cw_vm *vm)
{
	int			i;
	int 		ptr;
	int			distance;

	i = -1;
	ptr = 0;
	distance = CW_MEM_SIZE / vm->data.nbr_players;
	while (++i < vm->data.nbr_players)
	{
		ptr = distance * i;
		vm->players[i].initial_position = ptr;
		cw_vm_place_code(vm, vm->players[i].champion, ptr);
	}
}

/*
** Ininitialize arena and load player in arena
*/

int				cw_vm_ini_arena(t_cw_vm *vm)
{
	cw_vm_verify_enough_space(vm);
	cw_vm_place_player(vm);
	cw_vm_arena_dump(vm->arena, CW_MEM_SIZE + 1); // REMOVE
	return (CW_SUCCESS);
}
