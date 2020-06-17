#include "cw_asm.h"

/*
** Return the first index that marks the end of an arg.
*/

int				cw_asm_argend_index(t_cw_linst *linst, int index)
{
	while (linst->raw[index])
	{
		if (linst->raw[index] == CW_SEP_CHAR || ft_isblank(linst->raw[index]))
			return (index);
		index++;
	}
	return (index);
}
