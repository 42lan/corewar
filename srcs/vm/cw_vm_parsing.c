/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:06:54 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 05:12:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_parsing.h"
#include "cw_errors.h"

/*
** cw_vm_parsing() parse received arguments to fill t_cw_data structure
*/

int			cw_vm_parsing(int ac, char **av, t_cw_vm *vm)
{
	int		i;
	int		ret_value;
	char	*tmp;

	i = 0;
	if (ft_strnequ(av[i], "-dump\0", 6))
		if ((ret_value = cw_vm_set_dump(vm, av + 1, &i)) != CW_SUCCESS)
			return (ret_value);
	while (i < ac)
	{
		if ((tmp = ft_strtrim(av[i])) == NULL)
		{
			ft_printf("{red}Error malloc failed\n{}");
			return (CW_ERROR_MALLOC_FAILED);
		}
		if (vm->data.nbr_players >= CW_MAX_PLAYERS) //A revoir peut etre
		{
			ft_dprintf(2, "{red}Max number of players exceeded\n{}");
			return (CW_VM_ERROR_MAX_PLAYERS);
		}
		if (cw_vm_is_valid_extension(tmp, ".cor") == CW_SUCCESS)
		{
			if ((ret_value = cw_vm_set_player(vm, 0, tmp)) != CW_SUCCESS)
				return (ret_value);
		}
		else if (ft_strnequ(tmp, "-n\0", 3))
		{
			if ((ret_value = cw_vm_set_player_helper(vm, ac, av, &i)) != CW_SUCCESS)
				return (ret_value);
		}
		else
			cw_vm_usage();
		ft_strdel(&tmp);
		i++;
	}
	if (cw_vm_check_nbr_players(vm) != CW_SUCCESS)
		return (CW_VM_ERROR_NO_PLAYERS);
	return (CW_SUCCESS);
}
