#include "cw_asm.h"

/*
** Return the first index that is not a space after index.
** Return -1 if there is a syntax error.
*/

int				cw_asm_nextarg_index(t_cw_linst *linst, int index)
{
	while (ft_isblank(linst->raw[index]))
		index++;
	if (linst->raw[index] != CW_SEP_CHAR)
		return (-1);
	index++;
	while (ft_isblank(linst->raw[index]))
		index++;
	return (index);
}
