#include "cw_asm.h"

/*
** Return the first index that is not a space after index
*/

int				cw_asm_skip_spaces_index(t_cw_linst *linst, int index)
{
	while (ft_isblank(linst->raw[index]))
		index++;
	return (index);
}
