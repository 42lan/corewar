#include "cw_asm.h"

/*
** Try to translate a single linst to a label if ever it is one.
*/

int			cw_asm_translate_label(t_cw_asm *state, t_cw_linst *linst)
{
	ft_printf("{red}TODO: cw_asm_translate_label\n");
	(void)state;
	(void)linst;
	return (CW_SUCCESS);
}

/*
** Asm algorithm: Translation stage: labels only
** Search labels and translate them, so they have an index
** wich can be used for the other translation steps,
** when an op use a label.
*/

int			cw_asm_translate_labels(t_cw_asm *state)
{
	t_cw_linst	*linsts;
	int			i_linst;
	
	linsts = (t_cw_linst*)state->linsts->items;
	i_linst = 0;
	while (i_linst < state->linsts->item_count)
	{
		if (linsts[i_linst].type == CW_LINST_TYPE_RAW)
			cw_asm_translate_label(state, &linsts[i_linst]);
		i_linst++;
	}
	return (CW_SUCCESS);
}
