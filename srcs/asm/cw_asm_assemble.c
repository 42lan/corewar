#include "libft.h"

#include "cw_asm.h"

/*
** Asm algorithm: assemble stage.
** The internal champion is created.
*/

int				cw_asm_assemble(t_cw_asm *state)
{
	t_cw_linst	*insts;
	int			i_linst;

	if (!(state->champion->code = malloc(state->code_len)))
		return (CW_ERROR_MALLOC_FAILED);
	state->champion->code_len = state->code_len;
	insts = (t_cw_linst*)state->linsts->items;
	i_linst = 0;
	while (i_linst < state->linsts->item_count)
	{
		cw_linst_write(&insts[i_linst],
						state->champion->code + insts[i_linst].offset);
		i_linst++;
	}
	return (CW_SUCCESS);
}
