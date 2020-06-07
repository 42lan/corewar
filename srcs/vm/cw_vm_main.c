/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:04:40 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 05:32:58 by jthierce         ###   ########.fr       */
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

	if (argc < 2)
		cw_vm_usage();
	cw_vm_init_struct_vm(&vm);
	cw_vm_parsing(argc - 1 , argv + 1, &vm);
	cw_vm_read_player(&vm.data, vm.player);
	ft_printf("{green}Code len:{} %d\n", vm.player[0].champion->code_len);
	cw_vm_ini_arena(&vm);
	return (CW_SUCCESS);
}
