/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 22:07:59 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/17 19:21:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_vm.h"

t_cw_proc		*cw_vm_proc_create(int id, int pos)
{
	t_cw_proc	*processus;

	if (!(processus = (t_cw_proc *)malloc(sizeof(t_cw_proc))))
		return (NULL);
	id++;
	processus->carry = FALSE;
	processus->opc = -1;
	processus->last_live = -1;
	processus->wait_cycles = 0;
	processus->pos = pos;
	processus->jump = -1;
	processus->id = id;
	ft_bzero(processus->regs, sizeof(int) * CW_REG_NUMBER);
	processus->regs[0] = id * -1;
	processus->next = NULL;
	return (processus);
}

void			cw_vm_procs_destroy(t_cw_proc *head)
{
	t_cw_proc	*curr;

	while (head->next)
	{
		curr = head;
		head = head->next;
		ft_memdel((void **)&curr);
	}
	ft_memdel((void **)&head);
}

int				cw_vm_proc_count(t_cw_proc *head)
{
	int			count;
	t_cw_proc	*curr;

	count = 0;
	curr = head;
	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

void			cw_vm_proc_dump(t_cw_proc *proc)
{
	int			i;

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
