/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_magic_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 01:55:51 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/07 02:02:42 by amalsago         ###   ########.fr       */
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
		return (CW_VM_READ_ERROR);
	}
	magic_number_int = ft_bigendian32_read(magic_number);
	if (magic_number_int != CW_EXEC_MAGIC)
	{
		ft_dprintf(2, "{RED}NOT VALID MAGIC NUMBER\n{}");
		return(CW_VM_ERROR_NOT_VALID_PLAYER);
	}
	return (CW_SUCCESS);
}
