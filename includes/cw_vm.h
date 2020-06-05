/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 15:01:47 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/04 21:09:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_H
# define CW_VM_H

# define CW_MAX_PLAYERS			4
# define CW_FILENAME_MAX_LEN	128

# include <stdlib.h>
# include "cw_errors.h"
# include "cw_vm_parsing.h"
# include "cw_vm_player.h"

int		cw_vm_usage(void);
int		cw_vm_parsing(int argc, char **argv, t_cw_data *data);
int		cw_vm_read_player(t_cw_data *data, t_cw_champion players);

#endif
