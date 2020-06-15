/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_magic_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 01:55:51 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 03:42:58 by jthierce         ###   ########.fr       */
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
		ft_dprintf(2, "{red}ERROR READ MAGIC NUMBER\n{}");
		return (CW_VM_ERROR_READ);
	}
	magic_number_int = ft_bigendian32_read(magic_number);
	if (magic_number_int != CW_EXEC_MAGIC)
	{
		ft_dprintf(2, "{red}NOT VALID MAGIC NUMBER\n{}");
		return (CW_VM_ERROR_NOT_VALID_PLAYER);
	}
	return (CW_SUCCESS);
}
