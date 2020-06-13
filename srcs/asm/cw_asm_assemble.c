#include "libft.h"

#include "cw_asm.h"

/*
** Asm algorithm: assemble stage.
** The internal champion is created.
*/

int				cw_asm_assemble(t_cw_asm *state)
{
	state->champion->code_len = state->code_len;
	state->champion->code = malloc(state->code_len);
	ft_printf("{purple}TODO: cw_asm_assemble\n");
	return (CW_SUCCESS);
}
