/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:06:54 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/16 04:34:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_parsing.h"
#include "cw_errors.h"

static int	cw_vm_get_next_arg(char **av, int i, char **tmp)
{
	if ((*tmp = ft_strtrim(av[i])) == NULL)
	{
		ft_printf("{red}Error malloc failed\n{}");
		return (CW_ERROR_MALLOC_FAILED);
	}
	return (CW_SUCCESS);
}

static int	cw_vm_check_max_players(t_cw_vm *vm)
{
	if (vm->data.nbr_players >= CW_MAX_PLAYERS)
	{
		ft_dprintf(2, "{red}Max number of players exceeded\n{}");
		return (CW_VM_ERROR_MAX_PLAYERS);
	}
	return (CW_SUCCESS);
}

int			cw_vm_parsing_helper(int ac, char **av, t_cw_vm *vm, char **tmp)
{
	int		i;
	int		ret;

	i = -1;
	while (++i < ac)
	{
		if ((ret = cw_vm_get_next_arg(av, i, tmp)) != CW_SUCCESS)
			break ;
		if ((ret = cw_vm_check_max_players(vm)) != CW_SUCCESS)
			break ;
		if (cw_vm_is_valid_extension(*tmp, ".cor") == CW_SUCCESS)
		{
			if ((ret = cw_vm_set_player(vm, 0, *tmp)) != CW_SUCCESS)
				break ;
		}
		else if (ft_strnequ(*tmp, "-n\0", 3))
		{
			if ((ret = cw_vm_set_player_helper(vm, ac, av, &i)) != CW_SUCCESS)
				break ;
		}
		else
			cw_vm_usage();
		ft_strdel(tmp);
	}
	return (ret);
}

/*
** cw_vm_parsing() parse received arguments to fill t_cw_data structure
*/

int			cw_vm_parsing(int ac, char **av, t_cw_vm *vm)
{
	int		ret;
	char	*tmp;

	if (ft_strnequ(av[0], "-dump\0", 6))
	{
		if ((ret = cw_vm_set_dump(vm, av + 1)) != CW_SUCCESS)
			return (ret);
		av += 2;
		ac -= 2;
	}
	if (((ret = cw_vm_parsing_helper(ac, av, vm, &tmp)) != CW_SUCCESS)
		|| ((ret = cw_vm_check_nbr_players(vm) != CW_SUCCESS)))
	{
		ft_strdel(&tmp);
		return (ret);
	}
	return (CW_SUCCESS);
}
