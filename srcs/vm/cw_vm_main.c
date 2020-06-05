/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:04:40 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/05 19:55:36 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"

int			main(int argc, char **argv)
{
	t_cw_data	data;
	t_cw_player	*players;

	players = NULL;
	if (argc < 2)
		return (cw_vm_usage());
	cw_vm_parsing(argc - 1 , argv + 1, &data);
	cw_vm_read_player(&data, players);
	return (CW_SUCCESS);
}
