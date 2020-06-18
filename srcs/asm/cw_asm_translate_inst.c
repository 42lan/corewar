/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_translate_inst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:54 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 20:20:16 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

static int	translate_arg2(t_cw_asm *state, t_cw_inst *inst, char *str)
{
	if (str[0] == '%')
	{
		inst->types[inst->args_count] = CW_T_DIR;
		str += 1;
	}
	if (str[0] == ':')
	{
		inst->types[inst->args_count] |= CW_T_LAB;
		inst->args[inst->args_count] = cw_asm_get_label_index(state, &str[1]);
		if (inst->args[inst->args_count] == -1)
			return (CW_ASMR_LABEL_MISSING);
	}
	else
	{
ft_printf(" atoying '%s'\n", str);//
		if (ft_atoi00check(&inst->args[inst->args_count], str) < 0)
			return (CW_ASMR_INT_INVALID);
	}
	return (CW_SUCCESS);
}

/*
** This part only translate an arg to an inst, assuming it's the one
** being read.
*/

static int	translate_arg(t_cw_asm *state, t_cw_inst *inst, char *str)
{
	int		rst;

ft_printf(" translating argument '%s'\n", str);//
	inst->types[inst->args_count] = CW_T_IND;
	if (str[0] == 'r')
	{
		inst->types[inst->args_count] = CW_T_REG;
		str += 1;
ft_printf(" atoyinG '%s'\n", str);//
		if (ft_atoi00check(&inst->args[inst->args_count], str) < 0)
			return (CW_ASMR_INT_INVALID);
	}
	else
	{
		if ((rst = translate_arg2(state, inst, str)) < 0)
			return (rst);
	}
	inst->args_count += 1;
	return (CW_SUCCESS);
}

/*
** This part translate args of an inst recursively.
*/

static int	translate_inst3(t_cw_asm *state, t_cw_linst *linst, int i_arg)
{
	int		rst;
	int		i_end;
	char	bck;

	i_end = cw_asm_argend_index(linst, i_arg);
	bck = linst->raw[i_end];
	linst->raw[i_end] = '\0';
	rst = translate_arg(state, linst->inst, &linst->raw[i_arg]);
	linst->raw[i_end] = bck;
	ft_printf("{dim green} --\n");
	if (rst < 0)
		return (cw_asmr(rst, i_arg, linst));
	ft_printf("{dim green} --+\n");
	// Next arg
	if (cw_asm_nothing_at_end(linst, i_end) == CW_SUCCESS)
		return (CW_SUCCESS);
	if (linst->inst->args_count >= 3)
		return (cw_asmr(CW_ASMR_ARG_COUNT, i_arg, linst));
	if ((i_arg = cw_asm_nextarg_index(linst, i_end)) < 0)
		return (cw_asmr(CW_ASMR_SYNTAX, i_arg, linst));
	rst = translate_inst3(state, linst, i_arg);
	//cw_asmr(rst, i_arg, linst);
	return (rst);
}

/*
** This part translate an op assuming it is the one given and
** args starts at i_args.
*/

static int	translate_inst2(t_cw_asm *state, t_cw_linst *linst,
							const t_cw_op *op, int i_args)
{
	int			rst;
	uint32_t	i_arg;

	linst->inst = cw_inst_create();
	linst->inst->opc = op->opc;
	linst->inst->has_coding_byte = op->has_coding_byte;
	if ((rst = translate_inst3(state, linst, i_args)) < 0)
		return (rst);
	ft_printf("{dim green} --+++++\n");
	if (linst->inst->args_count != op->arg_count)
		return (cw_asmr(CW_ASMR_ARG_COUNT, i_args, linst));
	i_arg = 0;
	while (i_arg < linst->inst->args_count)
	{
		if (!(linst->inst->types[i_arg] & op->arg_types[i_arg]))
			return (cw_asmr(CW_ASMR_ARG_TYPE, i_arg, linst));
		i_arg++;
	}
	return (CW_SUCCESS);
}

/*
** Translate an inst. This is in fact a substep if insts translation.
*/

int			cw_asm_translate_inst(t_cw_asm *state, t_cw_linst *linst)
{
	int				i_op;
	int				i_end;
	char			bck;
	const t_cw_op	*op;

	i_op = cw_asm_skip_label_index(linst);
	if (cw_asm_nothing_at_end(linst, i_op) == CW_SUCCESS)
		return (CW_SUCCESS);
	i_op = cw_asm_skip_spaces_index(linst, i_op);
	i_end = cw_asm_skip_alnums_index(linst, i_op);
	bck = linst->raw[i_end];
	linst->raw[i_end] = '\0';
	op = cw_op_get_from_name(&linst->raw[i_op]);
	linst->raw[i_end] = bck;
	if (!op)
		return (cw_asmr(CW_ASMR_OP_UNKNOWN, i_op, linst));
	i_end = cw_asm_skip_spaces_index(linst, i_end);
	return (translate_inst2(state, linst, op, i_end));
}
