/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:06:54 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/06 10:36:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_parsing.h"
#include "cw_errors.h"
#include "cw_common.h"


/*
** cw_vm_print_data() prints data structure on standard output
*/
void	cw_vm_print_data(t_cw_data *data)
{
	ft_printf("data->nbr_cycles   = %d\n", data->nbr_cycles);
	ft_printf("data->nbr_players  = %d\n", data->nbr_players);
}

/*
** cw_vm_is_valid_extension() checks whether `argv` ends in `extension`
*/

int		cw_vm_is_valid_extension(const char *argv, const char *extension)
{
	if (argv == NULL || extension == NULL)
		return (CW_FAILURE);
	if ((extension = ft_strrchr(argv, '.')) != NULL)
		if (ft_strequ(extension, ".cor"))
			return (CW_SUCCESS);
	return (CW_FAILURE);
}

/*
** cw_vm_get_player() retrieves player's filename which must have .cor extension
*/


int		cw_vm_get_player(t_cw_data *data, char **argv)
{
	int		i;
	i = 0;
	if (ft_isstrnum(argv[i]))
	{
		// save -n id
		i += 1;
	}
	if (argv[i] == NULL || argv[i][0] == '\0')
		ft_printerr("filename is empty");
	if (cw_vm_is_valid_extension(argv[i], ".cor") == CW_FAILURE)
		ft_printerr("filename has incorrect extension");
	data->nbr_players += 1;
	return (CW_SUCCESS);
}

/*
** cw_vm_get_data() retrieves an integer from given argv and return its value
*/

int		cw_vm_get_data(char **argv)
{
	int			value;

	value = 0;
	if (argv[0] == NULL || argv[0][0] == '\0')
		ft_printerr("Data is empty");
	if (ft_atoi32check(&value, argv[0] + ft_strspn(argv[0], " \t")) != 0 || value <= 0)
	{
		ft_dprintf(2, "invalid data");
		exit(CW_VM_NO_VALID_ARGUMENT_DUMP);
	}
	argv++;
	return (value);
}

/*
** cw_vm_parsing() parse received arguments to fill t_cw_data structure
*/

int		cw_vm_parsing(int argc, char **argv, t_cw_vm *vm, t_cw_data *data)
{
	int			i;
	int			value;

	i = 0;
	value = 0;
	(void)vm;
	if (ft_strnequ(argv[i], "-dump\0", 6))
	{
		if (++i < argc)
		{
			ft_printf("---\n");
			data->nbr_cycles = cw_vm_get_data(argv + i++);
			vm->dump = 1;
		}
		else
			ft_printf("Dump with default value\n");
	}
	while (i < argc)
	{
		if (data->nbr_players >= CW_MAX_PLAYERS)
			ft_printerr("Max number of players exceeded");
		if (ft_strnequ(argv[i], "-n\0", 3) && i + 2 < argc)
		{
			cw_vm_get_player(data, argv + i + 2);
			i += 2;
		}
		else
			cw_vm_get_player(data, argv + i);
		i++;
	}
	if (data->nbr_players == 0)
		ft_printerr("0 players");
	cw_vm_print_data(data);
	return (CW_SUCCESS);
}
