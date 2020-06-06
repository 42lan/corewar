/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_valid_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:33:02 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/06 15:33:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"

/*
** cw_vm_read_magic_number() reads first 4 bytes of `.cor` file and checks
** the validity of magic number
*/

int		cw_vm_read_magic_number(int fd)
{
	unsigned char	magic_number[4];
	int32_t			magic_number_int;

	if (read(fd, magic_number, 4) != 4)
	{
		ft_dprintf(2, "{RED}ERROR READ MAGIC NUMBER\n{}");
		close(fd);
		return (CW_VM_READ_ERROR);
	}
	magic_number_int = ft_bigendian32_read(magic_number);
	if (magic_number_int != CW_EXEC_MAGIC)
	{
		ft_dprintf(2, "{RED}NOT VALID MAGIC NUMBER\n{}");
		close(fd);
		return(CW_VM_ERROR_NOT_VALID_PLAYER);
	}
	return (CW_SUCCESS);
}

int		cw_vm_valid_player(t_cw_data *data, t_cw_player *players)
{
	int fd;
	int i;
	int result;

	i = -1;
	while (++i < data->nbr_players)
	{
		if ((fd = open(data->filename[i], O_RDONLY)) == -1)
		{
			free(players);
			ft_dprintf(2, "{red}Cannot open file\n{}");
			exit(CW_VM_ERROR_OPEN_FAILED);
		}
		if ((result = cw_vm_read_magic_number(fd)) != CW_SUCCESS)
		{
			free(players);
			exit(result);
		}
		close(fd);
	}
	return (CW_SUCCESS);
}