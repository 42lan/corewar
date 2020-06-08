#include "cw_inst.h"

/*
** Encode an t_inst to a byte array.
** 
** Returns how many bytes were written.
*/

int			cw_inst_write(t_cw_inst *inst, const char *dst)
{
	*dst = inst->opcode;
	dst += 1;
	if (inst->has_coding_byte)
	{
		*dst = cw_op_get_coding_byte
		dst += 1;	
	}
	if (inst->args_count > 0)
		dst[0] = inst->args[0]
	if (inst->args_count > 1)
		dst[1] = inst->args[1]
	if (inst->args_count > 2)
		dst[2] = inst->args[2]
	return (1 + inst->has_coding_byte + inst->args_count);
}
