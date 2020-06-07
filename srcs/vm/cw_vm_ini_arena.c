/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_ini_arena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 03:04:40 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 11:14:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"
#include "cw_vm_arena.h"

/*
** Verify if the space in arena is enough to place all player
*/

static void	cw_vm_verify_enough_space(t_cw_vm *vm)
{
	unsigned int total;
	int i;
	int j;

	total = 0;
	i = -1;
	j = 0;
	ft_printf("{blue}salut0.5  %d \n{}", vm->data.nbr_players);
	while (++i < vm->data.nbr_players)
	{
		ft_printf("{pink}%d\n{}", vm->players[0].number);
		total += vm->players[i].champion->code_len;
	}
	ft_printf("{blue}salut1 %d\n{}", total);
	i = -1;
	while (j == 0 && ++i  < vm->data.nbr_players)
	{
		if (vm->players[i].champion->code_len > (unsigned int)(CW_MEM_SIZE / vm->data.nbr_players))
			j = 1;
	}
	if (total > CW_MEM_SIZE || (j == 1 && i < vm->data.nbr_players))
	{
		while (i != -1)
			cw_champion_destroy(&vm->players[i--].champion);
		free(vm->players);
		exit(CW_VM_ERRO_NOT_ENOUGH_SPACE_IN_ARENA);
	}
}

/*
**
*/

static void cw_vm_place_code(unsigned char *arena, t_cw_champion *champion, int ptr)
{
	unsigned int i;

	i = 0;
	while (i < champion->code_len)
	{
		arena[ptr + i] = champion->code[i];
		i++;
	} 
}

/*
**
*/

static void	cw_vm_place_player(unsigned char *arena, t_cw_vm *vm)
{
	int i;
	int ptr;
	int	distance;

	i = -1;
	ptr = 0;
	distance = CW_MEM_SIZE / vm->data.nbr_players;
	while (++i < vm->data.nbr_players)
	{
		cw_vm_place_code(arena, vm->players[i].champion, ptr);
		ptr = distance * i; 
	}
}

/*
** Ininitialize arena and load player in arena
*/

int		cw_vm_ini_arena(t_cw_vm *vm)
{
	unsigned char arena[CW_MEM_SIZE + 1];
	
	cw_vm_verify_enough_space(vm);
	ft_printf("{blue}salut\n{}");
	ft_bzero(arena, CW_MEM_SIZE + 1);
	cw_vm_place_player(arena, vm);
	ft_printf("{green}SUCCESS{}\n");
	return (CW_SUCCESS);
}
