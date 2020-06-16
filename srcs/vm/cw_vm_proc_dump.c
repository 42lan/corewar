/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_proc_dump.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:02:45 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/16 04:42:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"

void		cw_vm_proc_dump(t_cw_proc *proc)
{
	int		i;

	if (proc == NULL)
		return ;
	i = -1;
	ft_printf("{bold}+---- PROC  DUMP -----+{}\n");
	ft_printf("{bold}|{} C     %-14d{bold}|{}\n", proc->carry);
	ft_printf("{bold}|{} OPC   %-14d{bold}|{}\n", proc->opc);
	ft_printf("{bold}|{} LL    %-14d{bold}|{}\n", proc->last_live);
	ft_printf("{bold}|{} WC    %-14d{bold}|{}\n", proc->wait_cycles);
	ft_printf("{bold}|{} P     %-14d{bold}|{}\n", proc->pos);
	ft_printf("{bold}|{} J     %-14d{bold}|{}\n", proc->jump);
	ft_printf("{bold}|{} I     %-14d{bold}|{}\n", proc->id);
	ft_printf("{bold}|{} next  @%-13p{bold}|{}\n", proc->next);
	while (++i < CW_REG_NUMBER)
		ft_printf("{bold}|{} r%02d   0x%-12d{bold}|{}\n",
				i + 1, proc->regs[i]);
	ft_printf("{bold}+---------------------+{}\n");
}
