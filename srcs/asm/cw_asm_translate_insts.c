#include "cw_asm.h"

/*
** Asm algorithm: Translation stage:
** Translate the remaining linsts into inst when possible.
** This requieres labels to have been translated already.
*/

int			cw_asm_translate_insts(t_cw_asm *state)
{
	t_cw_linst	*insts;
	int			i_linst;
	
ft_printf("{purple}IS A\n");
	insts = (t_cw_linst*)state->linsts->items;
	i_linst = 0;
ft_printf("{purple}IS B\n");
	while (i_linst < state->linsts->item_count)
	{
ft_printf("{purple} IS C\n");
		insts[i_linst].offset = state->code_len;
		
		ft_printf("{red}TODO: cw_asm_translate_insts");
		
		state->code_len += cw_linst_size(&insts[i_linst]);
		i_linst++;
	}
ft_printf("{purple}IS D\n");
	return (-1);
}
