/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:20:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/14 23:29:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"

/*
** Open `.cor` file and take all information to fill player's structure
** Return error code when the file is not validate
*/

int			cw_vm_read_player(t_cw_vm *vm)
{
	int ret_value;

	if ((ret_value = cw_parsing_number_player(&vm->data)) != CW_SUCCESS)
		return (ret_value);
	if ((ret_value = cw_vm_valid_player(&vm->data, vm->players)) != CW_SUCCESS)
		return (ret_value);
	return (CW_SUCCESS);
}
