#include "libft.h"

#include "cw_asm.h"

/*
** Asm algorithm: Translation stage.
** The internal linsts items have their elements filled with
** data describing the instructions.
** The code_len is determined by all the instructions len.
*/

int				cw_asm_translate(t_cw_asm *state)
{
	int		rst;

	if ((rst = cw_asm_translate_labels(state)) < 0)
		return (rst);
	if ((rst = cw_asm_translate_insts(state)) < 0)
		return (rst);
	if ((rst = cw_asm_translate_insts_labels(state)) < 0)
		return (rst);
	return (rst);
}
