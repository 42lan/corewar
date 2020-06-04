/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:04:40 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/04 18:12:54 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"

int			main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("{red}No argument provided\n{}");
		return (CW_VM_NO_ARG);
	}
	cw_vm_parsing(argc - 1 , argv + 1);
	ft_printf("{yellow}corewar\n");
	return (CW_ERROR_BAD_DEVELOPPER);
}
