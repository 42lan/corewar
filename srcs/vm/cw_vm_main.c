/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:04:40 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/14 19:17:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"

void		cw_vm_init_struct_vm(t_cw_vm *vm)
{
	ft_bzero(vm, sizeof(vm));
	vm->dump = false;
	ft_bzero(vm->arena, sizeof(unsigned char) * (CW_MEM_SIZE + 1));
	ft_bzero(vm->players, sizeof(t_cw_player) * CW_MAX_PLAYERS);
	ft_memset(vm->data.assigned_nbr, -1, sizeof(int) * CW_MAX_PLAYERS);
}

void		free_memory(t_cw_vm *vm)
{
	int		i;

	i = -1;
	while (++i < vm->data.nbr_players)
	{
		ft_strdel(&vm->data.filename[i]);
		cw_champion_destroy(&vm->players->champion);
	}
}

int			main(int argc, char **argv)
{
	t_cw_vm		vm;

	if (argc < 2)
		cw_vm_usage();
	cw_vm_init_struct_vm(&vm);
	cw_vm_parsing(argc - 1 , argv + 1, &vm);
	cw_vm_read_player(&vm);
	cw_vm_ini_arena(&vm);
	cw_vm_game(&vm);
	//free_memory(&vm);
	return (CW_SUCCESS);
}
