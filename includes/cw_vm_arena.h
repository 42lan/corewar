/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_arena.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 03:52:07 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/09 14:45:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_ARENA_H
# define CW_VM_ARENA_H

# include "libft.h"
# include "cw_common.h"
# include "cw_errors.h"

# define CW_MEM_SIZE	(4 * 1024)
# define CW_IDX_MOD		(CW_MEM_SIZE / 8)

void	cw_vm_arena_dump(unsigned char *arena, unsigned int size);

#endif
