#include "cw_asm.h"

/*
** Check that there is nothing of interest in an linst at an index and after.
*/

int				cw_asm_nothing_at_end(t_cw_asm *state, t_cw_linst *linst,
									 int index)
{
	(void)state;
	while (1)
	{
		if (linst->raw[index] == '\0' || linst->raw[index] == '#')
			return (CW_SUCCESS);
		if (!ft_isblank(linst->raw[index]))
			return (CW_ASM_ERROR_UNEXPECTED);
		index++;
	}
	return (CW_ASM_ERROR_UNEXPECTED);
}
