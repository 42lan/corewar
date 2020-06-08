#include "cw_op.h"

/*
** Get the length in bytes of an argument, from it's type. 
*/

uint32_t	cw_op_get_arg_len(t_cw_arg_type type)
{
	if (type & CW_T_REG)
		return (CW_REG_SIZE);
	if (type & CW_T_DIR)
		return (CW_DIR_SIZE);
	if (type & CW_T_IND)
		return (CW_IND_SIZE);
	if (type & CW_T_LAB)
		return (CW_IND_SIZE);
	return (0);
}
