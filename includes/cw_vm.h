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

# include <stdlib.h>
# include "cw_errors.h"
# include "cw_vm_parsing.h"

int		cw_vm_usage(void);
int		cw_vm_parsing(int argc, char **argv, t_cw_data *data);

#endif
