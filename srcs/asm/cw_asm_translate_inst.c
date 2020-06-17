#include "cw_asm.h"

static int  translate_arg2(t_cw_asm *state, t_cw_inst *inst, char *str)
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
			return (CW_ASM_ERROR_MISSING_LABEL);
	}
	else
		if (ft_atoi32check(&inst->args[inst->args_count], str) != 0)
			return (CW_ASM_ERROR_INVALID_INT);
	return (CW_SUCCESS);
}

static int	translate_arg(t_cw_asm *state, t_cw_inst *inst, char *str)
{
	int		rst;

	inst->types[inst->args_count] = CW_T_IND;
	if (str[0] == 'r')
	{
		inst->types[inst->args_count] = CW_T_REG;
		str += 1;
		if (ft_atoi32check(&inst->args[inst->args_count], str) != 0)
			return (CW_ASM_ERROR_INVALID_INT);
	}
	else
	{
		if ((rst = translate_arg2(state, inst, str)))
			return (rst);
	}
	inst->args_count += 1;
	return (CW_SUCCESS);
}

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
	if (rst < 0)
		return (rst);
	// Next arg
	if (cw_asm_nothing_at_end(state, linst, i_end) == CW_SUCCESS)
		return (CW_SUCCESS);
	if (linst->inst->args_count >= 3)
		return (CW_ASM_ERROR_ARG_COUNT);
	i_arg = cw_asm_nextarg_index(linst, i_end);
	return (translate_inst3(state, linst, i_arg));
}

static int	translate_inst2(t_cw_asm *state, t_cw_linst *linst,
							const t_cw_op *op, int i_args)
{
	int			rst;
	uint32_t	i_arg;

	linst->inst = cw_inst_create();
	linst->inst->opc = op->opc;
	if ((rst = translate_inst3(state, linst, i_args)) < 0)
		return (rst);
	if (linst->inst->args_count != op->arg_count)
		return (CW_ASM_ERROR_ARG_COUNT);
	i_arg = 0;
	while (i_arg < linst->inst->args_count)
	{
		if (!(linst->inst->types[i_arg] & op->arg_types[i_arg]))
			return (CW_ASM_ERROR_ARG_TYPE);
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

ft_printf("{purple} ---\n");
	i_op = cw_asm_skip_label_index(linst);
	i_op = cw_asm_skip_spaces_index(linst, i_op);
	i_end = cw_asm_skip_alnums_index(linst, i_op);
	bck = linst->raw[i_end];
	linst->raw[i_end] = '\0';
	op = cw_op_get_from_name(&linst->raw[i_op]);
	linst->raw[i_end] = bck;
ft_printf("{purple} unknown op %s\n", linst->raw);
	if (!op)
		return (CW_ASM_ERROR_UNKNOWN_OP);
	i_end = cw_asm_skip_spaces_index(linst, i_end);
	return (translate_inst2(state, linst, op, i_end));
}
