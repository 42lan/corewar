/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_valid_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:33:02 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/14 23:33:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"


/*
** cw_vm_verify_file_structure() calls other functions to verify the validity
** of `.cor` file
*/

static int		cw_vm_verify_file_structure(int fd, t_cw_player *player)
{
	int			ret;

	if (((ret = cw_vm_read_magic_number(fd)) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_name(fd, player)) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_null(fd, "NAME")) != CW_SUCCESS)
		|| ((ret = cw_vm_read_exec_code_len(fd, player)) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_comment(fd, player)) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_null(fd, "COMMENT")) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_exec_code(fd, player)) != CW_SUCCESS))
	{
		close(fd);
		return (ret);
	}
	return (CW_SUCCESS);
}

/*
** cw_vm_open_file() opens given file and return its fd
*/

static int		cw_vm_open_file(const char *filename)//, t_cw_player *players, int i)
{
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_dprintf(2, "{red}Cannot open file %s\n{}", filename);
		return (CW_VM_ERROR_OPEN_FAILED);
	}
	return (fd);
}

/*
** cw_vm_create_champion() creates champion
*/

static int		cw_vm_create_champion(t_cw_player *players, int i)
{
	if (cw_champion_create(&players[i].champion) != CW_SUCCESS)
	{
		ft_dprintf(2, "{red}Creation of champion failed\n{}");
		return (CW_ERROR_MALLOC_FAILED);
	}
	return (CW_SUCCESS);
}

/*
** cw_vm_valid_player() opens `.cor` file, create champions and checks the
** validity of data provided in `.cor`
*/

int				cw_vm_valid_player(t_cw_data *data, t_cw_player *players)
{
	int			i;
	int			fd;
	int			ret_value;

	i = -1;
	while (++i < data->nbr_players)
	{
		if ((fd = cw_vm_open_file(data->filename[i])) <= 0)
			return (CW_VM_ERROR_OPEN_FAILED);
		if (cw_vm_create_champion(players, i) != CW_SUCCESS)
			return (CW_ERROR_MALLOC_FAILED);
		if ((ret_value = cw_vm_verify_file_structure(fd, &players[i])) != CW_SUCCESS)
			return (ret_value);
		close(fd);
	}
	return (CW_SUCCESS);
}
