/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_set_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 04:57:43 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/17 18:34:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_errors.h"

/*
** cw_vm_set_player() retrieves player's filename which must have .cor extension
*/

int				cw_vm_set_player(t_cw_vm *vm, int assigned_nbr, char *filename)
{
	static int	j = 0;
	static int	cnt = INT16_MIN;

	if (filename == NULL || filename[0] == '\0')
	{
		ft_dprintf(2, "{red}Player's filename expected\n{}");
		return (CW_VM_ERROR_FILE_EXPECTED);
	}
	if (cw_vm_is_valid_extension(filename, ".cor") == CW_FAILURE)
	{
		ft_dprintf(2, "{red}Player's filename has an incorrect extension\n{}");
		return (CW_VM_ERROR_FILE_EXTENSION);
	}
	if ((vm->data.filename[j] = ft_strdup(filename)) == NULL)
	{
		ft_printf("{red}Error malloc failed\n{}");
		return (CW_ERROR_MALLOC_FAILED);
	}
	vm->data.assigned_nbr[j++] = (assigned_nbr > 0) ? assigned_nbr : ++cnt;
	vm->data.nbr_players += 1;
	return (CW_SUCCESS);
}

/*
** cw_vm_set_player_helper() checks if -n is followed by an integer, then it
** retrives assigned_nbr from av and pass it to cw_vm_set_player()
*/

int				cw_vm_set_player_helper(t_cw_vm *vm, int ac, char **av, int *i)
{
	int			assigned_nbr;
	int			ret;

	if (*i + 1 < ac)
	{
		if (ft_atoi32check(&assigned_nbr, av[*i + 1]) != 0 || assigned_nbr <= 0)
		{
			ft_dprintf(2, "{red}Player's ID must be between 1 and INT_MAX\n{}");
			return (CW_VM_ERROR_ID_LIMITS);
		}
		ret = cw_vm_set_player(vm, assigned_nbr, av[*i + 2]);
		if (ret != CW_SUCCESS)
			return (ret);
		*i += 2;
	}
	else
	{
		ft_dprintf(2, "{red}Player's number expected after -n\n{}");
		return (CW_VM_ERROR_ID_EXPECTED);
	}
	return (CW_SUCCESS);
}
