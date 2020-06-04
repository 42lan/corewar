/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:06:54 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/05 01:35:45 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_parsing.h"
#include "cw_errors.h"
#include "cw_common.h"


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


int		cw_vm_get_player(t_cw_data *data, const char *argv)
{
	int		i;

	i = -1;
	if (argv == NULL)
		ft_printerr("cw_vm_get_player()", "filename is empty");
	if (ft_strlen(argv) > CW_FILENAME_MAX_LEN)
		ft_printerr("cw_vm_get_player()", "filename is too large");
	if (cw_vm_is_valid_extension(argv, ".cor") == CW_FAILURE)
		ft_printerr("cw_vm_get_player()", "filename has incorrect extension");
	ft_strcpy(data->filename, argv);
	return (CW_SUCCESS);
}

/*
** cw_vm_get_data() retrieves an integer from given argv and return its value
*/

int		cw_vm_get_data(const char *argv, char *tmp)
{
	int			value;

	value = 0;
	if (argv)
		if (ft_atoi32check(&value, argv + ft_strspn(argv, " \t")) != 0 || value <= 0)
		{
			ft_printf("{red}ERROR: cw_vm_get_data(){}\n");
			free(tmp);
			exit(CW_VM_NO_VALID_ARGUMENT_DUMP);
		}
	return (value);
}

/*
** cw_vm_parsing() parse received arguments to fill t_cw_data structure
*/

int		cw_vm_parsing(int argc, char **argv, t_cw_data *data)
{
	int			i;
	char		*tmp;

	i = -1;
	while (++i < argc)
	{
		tmp = ft_strtrim(argv[i]);
		if (ft_strequ(tmp, "-dump") == 1)
		{
			data->nbr_cycles = cw_vm_get_data(argv[++i], tmp);
			ft_printf("data->nbr_cycles = %d\n", data->nbr_cycles);
		}
		else if (ft_strequ(tmp, "-n") == 1)
		{
			data->number = cw_vm_get_data(argv[++i], tmp);
			ft_printf("data->number = %d\n", data->number);
			cw_vm_get_player(data, argv[i + 1]);
		}
		free(tmp);
	}
	return (CW_SUCCESS);
}
