#include "cw_op.h"

/*
** Get the coding code for a coding type.
**
** Note that a given argument always has 1 single type,
** but an argument for an op can have several possible types.
** This function only handle the first case, not the later (wich is nonsense).
*/

t_cw_coding_code		cw_op_get_coding_code(t_cw_arg_type type)
{
	if (type & CW_T_REG)
		return (CW_REG_CODE);
	if (type & CW_T_IND)
		return (CW_IND_CODE);
	if (type & CW_T_DIR)
		return (CW_DIR_CODE);
	return (0);
}
