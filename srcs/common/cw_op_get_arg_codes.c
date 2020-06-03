#include "cw_op.h"

/*
** Get all the coding codes separately, from a coding byte.
**
** Note that this is trivial, and you may not need to use an array of
** coding codes and this function to fill it.
*/

void					cw_op_get_coding_codes(t_cw_arg_code *out3,
											t_cw_coding_byte coding_byte)
{
	out3[0] = (coding_byte >> 6) & 0x03;
	out3[1] = (coding_byte >> 4) & 0x03;
	out3[2] = (coding_byte >> 2) & 0x03;
}
