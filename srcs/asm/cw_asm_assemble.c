#include "libft.h"

#include "cw_asm.h"

static int		assemble(t_cw_asm *state, t_cw_linst *linst)
{
	if (linst->literal)
	{
		if (linst->literal->type == CW_LITERAL_TYPE_NAME)
			if (!state->champion->name)
				state->champion->name = ft_strdup(linst->literal->value);
		if (linst->literal->type == CW_LITERAL_TYPE_COMMENT)
			if (!state->champion->name)
				state->champion->comment = ft_strdup(linst->literal->value);
	}
	cw_linst_write(linst, state->champion->code + linst->offset);
	return (CW_SUCCESS);
}

/*
** Asm algorithm: assemble stage.
** The internal champion is created.
*/

int				cw_asm_assemble(t_cw_asm *state)
{
	int			rst;
	t_cw_linst	*insts;
	int			i_linst;

	rst = CW_SUCCESS;
	if (!(state->champion->code = malloc(state->code_len)))
		return (CW_ERROR_MALLOC_FAILED);
	state->champion->code_len = state->code_len;
	insts = (t_cw_linst*)state->linsts->items;
	i_linst = 0;
	while (i_linst < state->linsts->item_count)
	{
		if ((rst = assemble(state, &insts[i_linst])) < 0)
			return (rst);
		i_linst++;
	}
	return (rst);
}
