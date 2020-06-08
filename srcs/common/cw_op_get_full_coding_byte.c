#include "cw_op.h"

/*
** Get a coding byte from an array of argument types.
** Unused argument types must be set to 0.
*/

t_cw_coding_byte		cw_op_get_full_coding_byte(t_cw_arg_type *type3)
{
	t_cw_coding_byte		out;

	out = 0;
	out |= cw_op_get_coding_byte(type3[0], 0);
	if (type3[1] != 0)
	{
		out |= cw_op_get_coding_byte(type3[1], 1);
		if (type3[2] != 0)
			out |= cw_op_get_coding_byte(type3[2], 2);
	}
	return (out);
}
