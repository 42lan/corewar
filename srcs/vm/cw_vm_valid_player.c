/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_valid_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:33:02 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/10 14:01:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"


/*
** cw_vm_verify_file_structure() calls other functions to verify the validity
** of `.cor` file
*/

static int		cw_vm_verify_file_structure(int fd, t_cw_player *players, int i)
{
	int			ret;
	t_cw_player	*player;

	player = &players[i];
	if (((ret = cw_vm_read_magic_number(fd)) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_name(fd, player)) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_null(fd, "NAME")) != CW_SUCCESS)
		|| ((ret = cw_vm_read_exec_code_len(fd, player)) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_comment(fd, player)) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_null(fd, "COMMENT")) != CW_SUCCESS)
		|| ((ret = cw_vm_read_champion_exec_code(fd, player) != CW_SUCCESS)))
	{
		close(fd);
		while (i != -1)
			cw_champion_destroy(&players[i--].champion);
		exit(ret);
	}
	return (CW_SUCCESS);
}

/*
** cw_vm_open_file() opens given file and return its fd
*/

static int		cw_vm_open_file(const char *filename, t_cw_player *players, int i)
{
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		while (--i != -1)
			cw_champion_destroy(&players[i].champion);
		ft_dprintf(2, "{red}Cannot open file %s\n{}", filename);
		exit(CW_VM_ERROR_OPEN_FAILED);
	}
	return (fd);
}

/*
** cw_vm_create_champion() creates champion
*/

static void		cw_vm_create_champion(t_cw_player *players, int i)
{
	if (cw_champion_create(&players[i].champion) != CW_SUCCESS)
	{
		while (i != -1)
			cw_champion_destroy(&players[i--].champion);
		ft_dprintf(2, "{red}Creation of champion failed\n{}");
		exit(CW_VM_ERROR_OPEN_FAILED);
	}
}

/*
** cw_vm_valid_player() opens `.cor` file, create champions and checks the
** validity of data provided in `.cor`
*/

int				cw_vm_valid_player(t_cw_data *data, t_cw_player *players)
{
	int			i;
	int			fd;

	i = -1;
	while (++i < data->nbr_players)
	{
		fd = cw_vm_open_file(data->filename[i], players, i);
		cw_vm_create_champion(players, i);
		cw_vm_verify_file_structure(fd, players, i);
		close(fd);
	}
	return (CW_SUCCESS);
}
