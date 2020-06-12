#include "libft.h"

/*
** Print an asm error code and return the same.
*/

int			cw_asm_error(int code)
{
	if (code == 0)
		return (code);
	if (code < 0)
		ft_dprintf(2, "Error %d!", code);
	if (code > 0)
		ft_dprintf(2, "Error %d!", code);
	return (code);
}
