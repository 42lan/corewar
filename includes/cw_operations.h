/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:04:30 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/16 04:40:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_OPERATIONS_H
# define CW_OPERATIONS_H

# include "cw_vm.h"
# include "cw_inst.h"

typedef void	(*t_op_p)(t_cw_vm *vm);

void			cw_vm_op_live(t_cw_vm *vm);
void			cw_vm_op_ld(t_cw_vm *vm);
void			cw_vm_op_st(t_cw_vm *vm);
void			cw_vm_op_add(t_cw_vm *vm);
void			cw_vm_op_sub(t_cw_vm *vm);
void			cw_vm_op_and(t_cw_vm *vm);
void			cw_vm_op_or(t_cw_vm *vm);
void			cw_vm_op_xor(t_cw_vm *vm);
void			cw_vm_op_zjmp(t_cw_vm *vm);
void			cw_vm_op_ldi(t_cw_vm *vm);
void			cw_vm_op_sti(t_cw_vm *vm);
void			cw_vm_op_fork(t_cw_vm *vm);
void			cw_vm_op_lld(t_cw_vm *vm);
void			cw_vm_op_lldi(t_cw_vm *vm);
void			cw_vm_op_lfork(t_cw_vm *vm);
void			cw_vm_op_aff(t_cw_vm *vm);

static t_op_p	g_op_table[] = {
	cw_vm_op_live, cw_vm_op_ld, cw_vm_op_st, cw_vm_op_add, cw_vm_op_sub,
	cw_vm_op_and, cw_vm_op_or, cw_vm_op_xor, cw_vm_op_zjmp, cw_vm_op_ldi,
	cw_vm_op_sti, cw_vm_op_fork, cw_vm_op_lld, cw_vm_op_lldi, cw_vm_op_lfork,
	cw_vm_op_aff
};

#endif
