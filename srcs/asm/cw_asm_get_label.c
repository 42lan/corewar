#include "libft.h"

#include "cw_asm.h"

/*
** Get the index of a label.
*/

int			cw_asm_get_label_index(t_cw_asm *state, char *name)
{
	t_cw_linst	*linsts;
	int			i_linst;
	
	linsts = (t_cw_linst*)(state->linsts->items);
	i_linst = 0;
	while (i_linst < state->linsts->item_count)
	{
		if (linsts[i_linst].type == CW_LINST_TYPE_LABEL)
			if (ft_strcmp((char*)linsts[i_linst].label, name) == 0)
				return (i_linst);
		i_linst++;
	}
	return (-1);
}

/*
** Get the code offset of a label.
*/

int			cw_asm_get_label_offset(t_cw_asm *state, int index)
{
	t_cw_linst	*linsts;
	t_cw_linst	*linst;
	
	if (index == 0)
		return (0);
	linsts = (t_cw_linst*)(state->linsts->items);
	linst = &(linsts[index]);	
	return (linst->offset);
}
