#include "cw_inst.h"

/*
** Get the size needed to output this t_cw_inst in binary.
*/

int					cw_inst_size(t_cw_inst *inst)
{
	int		total;

	total = 0;
	total += 1;
	total += inst->has_coding_byte;
	total += cw_inst_arg_size(inst->opc, inst->types[0]);
	total += cw_inst_arg_size(inst->opc, inst->types[1]);
	total += cw_inst_arg_size(inst->opc, inst->types[2]);
	return (total);
}

/*
** Get the size of an argument from its opc and type.
*/

int					cw_inst_arg_size(t_cw_opc opc, t_cw_arg_type type)
{
	const t_cw_op	*ops;

	if (opc < CW_OP_MIN || opc >= CW_OP_MAX)
		return (0);
	if (type & CW_T_REG)
		return (1);
	if (type & CW_T_IND)
		return (2);
	ops = cw_op_list();
	if (type & CW_T_DIR)
		return (ops[opc - 1].requieres_label ? 2 : 4);
	return (0);
}
