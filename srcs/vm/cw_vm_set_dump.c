/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_set_dump.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 04:59:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 05:13:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_errors.h"

/*
** cw_vm_set_dump() set dump value in t_cw_data and TRUE boolean to t_cw_vm
*/

int			cw_vm_set_dump(t_cw_vm *vm, char **av, int *i)
{
	char	*tmp;

	if (*av == NULL || *av[0] == '\0' || !ft_isstrnum(*av))
	{
		ft_dprintf(2, "{red}A positive number expected after -dump\n{}");
		return (CW_VM_ERROR_DUMP_NUM);
	}
	if ((tmp = ft_strtrim(*av)) == NULL)
	{
		ft_printf("{red}Error malloc failed\n{}");
		return (CW_ERROR_MALLOC_FAILED);
	}
	if (ft_atoi32check(&vm->dump, tmp) != 0 || vm->dump <= 0)
	{
		ft_dprintf(2, "{red}Number of cycle must be between 1 and INT_MAX\n{}");
		return (CW_VM_ERROR_CYCLE_LIMITS);
	}
	ft_strdel(&tmp);
	*i += 2;
	return (CW_SUCCESS);
}
