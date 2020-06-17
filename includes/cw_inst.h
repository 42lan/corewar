/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:20:24 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:20:28 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_INST_H
# define CW_INST_H

# include "libft.h"
# include "cw_op.h"

/*
** t_cw_inst:
**
** Instruction.
** Represent an instance of an op, with determined arguments.
** opc: The opc corresponding to an op.
** args_count: How many args does this op have.
** args: Unresolved args, not the real values.
** types: Types of each argument in args.
*/

typedef struct s_cw_inst	t_cw_inst;

struct						s_cw_inst
{
	t_cw_opc		opc;
	t_bool			has_coding_byte;
	unsigned int	args_count;
	int				args[3];
	t_cw_arg_type	types[3];
};

t_cw_inst					*cw_inst_create(void);
void						cw_inst_destroy(t_cw_inst **inst);

int							cw_inst_arg_size(t_cw_opc opc, t_cw_arg_type t);
int							cw_inst_size(t_cw_inst *inst);
int							cw_inst_write(t_cw_inst *inst, unsigned char *dst);

void						cw_inst_init(t_cw_inst *inst);
void						cw_inst_dump(t_cw_inst *inst);

#endif
