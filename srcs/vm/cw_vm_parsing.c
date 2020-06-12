/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:06:54 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/12 12:57:04 by amalsago         ###   ########.fr       */
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
	int		i;

	i = -1;
	ft_printf("Number of cycles    = %d\n", data->nbr_cycles);
	ft_printf("Number of players   = %d\n", data->nbr_players);
	while (++i < data->nbr_players && data->filename[i])
	{
		ft_printf("Player %d:\n", i + 1);
		ft_printf(" assigned ID  = %d\n", data->assigned_nbr[i]);
		ft_printf(" filename     = %s\n", data->filename[i]);
	}
}

/*
** cw_vm_is_valid_extension() checks whether `av` ends in `extension`
*/

int		cw_vm_is_valid_extension(const char *av, const char *extension)
{
	if (av == NULL || !*av || extension == NULL || !*extension)
		return (CW_FAILURE);
	if ((extension = ft_strrchr(av, '.')) != NULL)
		if (ft_strequ(extension, ".cor"))
			return (CW_SUCCESS);
	return (CW_FAILURE);
}

/*
** cw_vm_set_player() retrieves player's filename which must have .cor extension
*/

int		cw_vm_set_player(t_cw_vm *vm, int assigned_nbr, char *filename)
{
	static int	j = 0;
	static int	cnt = 0;

	if (filename == NULL || filename[0] == '\0')
		ft_printerr("Player's filename expected", CW_VM_FILE_EXPECTED);
	if (cw_vm_is_valid_extension(filename, ".cor") == CW_FAILURE)
		ft_printerr("Player's filename has an incorrect extension", CW_VM_FILE_EXTENSION);
	vm->data.filename[j] = ft_strdup(filename);
	vm->data.assigned_nbr[j++] = (assigned_nbr > 0) ? assigned_nbr : --cnt;
	vm->data.nbr_players += 1;
	return (CW_SUCCESS);
}

/*
** cw_vm_set_dump() set dump value in t_cw_data and true boolean to t_cw_vm
*/

void	cw_vm_set_dump(t_cw_vm *vm, char **av, int *i)
{
	char		*tmp;

	if (*av == NULL || *av[0] == '\0' || !ft_isstrnum(*av))
		ft_printerr("A positive number expected after -dump", CW_VM_DUMP_NUM);
	tmp = ft_strtrim(*av);
	if (ft_atoi32check(&vm->data.nbr_cycles, tmp) != 0
		|| vm->data.nbr_cycles <= 0)
		ft_printerr("Number of cycles should be between 1 and INT_MAX", CW_VM_CYCLE_LIMITS);
	ft_strdel(&tmp);
	vm->dump = true;
	*i += 2;
}

/*
** cw_vm_set_player_helper() checks if -n is followed by an integer, then it
** retrives assigned_nbr from av and pass it to cw_vm_set_player()
*/

void	cw_vm_set_player_helper(t_cw_vm *vm, int ac, char **av, int *i)
{
	int		assigned_nbr;

	if (*i + 1 < ac)
	{
		if (ft_atoi32check(&assigned_nbr, av[*i + 1]) != 0 || assigned_nbr <= 0)
			ft_printerr("Player's assigned ID should be between 1 and INT_MAX", CW_VM_ID_LIMITS);
		cw_vm_set_player(vm, assigned_nbr, av[*i + 2]);
		*i += 2;
	}
	else
		ft_printerr("Player's number expected after -n", CW_VM_ID_EXPECTED);
}

/*
** cw_vm_parsing() parse received arguments to fill t_cw_data structure
*/

int		cw_vm_parsing(int ac, char **av, t_cw_vm *vm)
{
	int			i;
	char		*tmp;

	i = 0;
	if (ft_strnequ(av[i], "-dump\0", 6))
		cw_vm_set_dump(vm, av + 1, &i);
	while (i < ac)
	{
		tmp = ft_strtrim(av[i]);
		if (vm->data.nbr_players >= CW_MAX_PLAYERS)
			ft_printerr("Max number of players exceeded", CW_VM_MAX_PLAYERS);
		if (cw_vm_is_valid_extension(tmp, ".cor") == CW_SUCCESS)
			cw_vm_set_player(vm, 0, tmp);
		else if (ft_strnequ(tmp, "-n\0", 3))
			cw_vm_set_player_helper(vm, ac, av, &i);
		else
			cw_vm_usage();
		ft_strdel(&tmp);
		i++;
	}
	cw_vm_check_nbr_players(vm);
	return (CW_SUCCESS);
}

/*
** cw_vm_check_nbr_players() checks if there is at least one player provided,
** otherwise it teminate program
*/

void	cw_vm_check_nbr_players(t_cw_vm *vm)
{
	if (vm->data.nbr_players == 0)
	{
		ft_printerr("No players provided", CW_VM_NO_PLAYERS);
		exit(0);
	}
}
