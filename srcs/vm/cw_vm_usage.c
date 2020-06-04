/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 21:07:33 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/05 01:39:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include <unistd.h>

int		cw_vm_usage(void)
{
	ft_printerr(STDERR_FILENO, "usage: " \
			"./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
	exit(CW_VM_NO_ARG);
}
