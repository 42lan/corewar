/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:20:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 11:09:27 by amalsago         ###   ########.fr       */
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
	cw_parsing_number_player(&vm->data);
	cw_vm_valid_player(&vm->data, vm->players);
	return (CW_SUCCESS);
}
