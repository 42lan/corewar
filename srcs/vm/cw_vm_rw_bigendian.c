/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_rw_bigendian.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 01:22:08 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/17 01:22:08 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "cw_vm.h"

/*
** Read an int32 from a byte array encoded in big endian.
*/

int32_t		cw_vm_bigendian32_read(unsigned char *data32, int index)
{
	int32_t		total;

	total = 0;
	total |= (int32_t)data32[(index + 3) % CW_MEM_SIZE] << 0;
	total |= (int32_t)data32[(index + 2) % CW_MEM_SIZE] << 8;
	total |= (int32_t)data32[(index + 1) % CW_MEM_SIZE] << 16;
	total |= (int32_t)data32[(index + 0) % CW_MEM_SIZE] << 24;
	return (total);
}

/*
** Write an int32 to a byte array encoded in big endian.
*/

void		cw_vm_bigendian32_write(unsigned char *data32, int index, int32_t int32)
{
	data32[(index + 3) % CW_MEM_SIZE] = (int32 >> 0) & 0xFF;
	data32[(index + 2) % CW_MEM_SIZE] = (int32 >> 8) & 0xFF;
	data32[(index + 1) % CW_MEM_SIZE] = (int32 >> 16) & 0xFF;
	data32[(index + 0) % CW_MEM_SIZE] = (int32 >> 24) & 0xFF;
}

/*
** Read an int16 from a byte array encoded in big endian.
*/

int16_t		cw_vm_bigendian16_read(unsigned char *data16, int index)
{
	int16_t		total;

	total = 0;
	total |= (int16_t)data16[(index + 1) % CW_MEM_SIZE] << 0;
	total |= (int16_t)data16[(index + 0) % CW_MEM_SIZE] << 8;
	return (total);
}

/*
** Write an int16 to a byte array encoded in big endian.
*/

void	cw_vm_bigendian16_write(unsigned char *data16, int index, int16_t int16)
{
	data16[(index + 1) % CW_MEM_SIZE] = (int16 >> 0) & 0xFF;
	data16[(index + 0) % CW_MEM_SIZE] = (int16 >> 8) & 0xFF;
}
