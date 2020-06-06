/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:04:40 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/06 13:48:07 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"

void		cw_vm_init_struct_vm(t_cw_vm *vm)
{
	ft_bzero(vm, sizeof(vm));
	ft_memset(vm->data.assigned_nbr, -1, sizeof(vm->data.assigned_nbr));
}

int			main(int argc, char **argv)
{
	t_cw_vm		vm;
	t_cw_player	*players;

	players = NULL;
	if (argc < 2)
		cw_vm_usage();
	cw_vm_init_struct_vm(&vm);
	cw_vm_parsing(argc - 1 , argv + 1, &vm);
	cw_vm_read_player(&vm.data, players);
	return (CW_SUCCESS);
}
