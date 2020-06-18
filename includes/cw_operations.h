/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:04:30 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/18 10:32:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_OPERATIONS_H
# define CW_OPERATIONS_H

# include "cw_vm.h"
# include "cw_inst.h"

typedef void	(*t_op_p)(t_cw_vm *vm);

void			cw_vm_live(t_cw_vm *vm);
void			cw_vm_ld(t_cw_vm *vm);
void			cw_vm_st(t_cw_vm *vm);
void			cw_vm_add(t_cw_vm *vm);
void			cw_vm_sub(t_cw_vm *vm);
void			cw_vm_and(t_cw_vm *vm);
void			cw_vm_or(t_cw_vm *vm);
void			cw_vm_xor(t_cw_vm *vm);
void			cw_vm_zjmp(t_cw_vm *vm);
void			cw_vm_ldi(t_cw_vm *vm);
void			cw_vm_sti(t_cw_vm *vm);
void			cw_vm_fork(t_cw_vm *vm);
void			cw_vm_lld(t_cw_vm *vm);
void			cw_vm_lldi(t_cw_vm *vm);
void			cw_vm_lfork(t_cw_vm *vm);
void			cw_vm_aff(t_cw_vm *vm);

static t_op_p	g_op_table[] = {
	cw_vm_live,
	cw_vm_ld, cw_vm_st,
	cw_vm_add, cw_vm_sub,
	cw_vm_and, cw_vm_or, cw_vm_xor,
	cw_vm_zjmp,
	cw_vm_ldi, cw_vm_sti,
	cw_vm_fork, cw_vm_lld,
	cw_vm_lldi, cw_vm_lfork,
	cw_vm_aff
};

#endif
