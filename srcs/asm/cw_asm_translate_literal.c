#include "cw_asm.h"

static int	translate_literal2(t_cw_asm *state, t_cw_linst *linst,
								int type, int i_space)
{
	int		rst;
	int		i_quote;

	i_quote = cw_asm_skip_spaces_index(linst, i_space);
	if ((rst = cw_asm_dismember_string(state, linst, i_quote)) < 0)
		return (rst);
	linst->literal = cw_literal_create(type, &linst->raw[i_quote + 1]);
		return (CW_ERROR_MALLOC_FAILED);
	linst->raw[i_quote] = '\"';
	linst->raw[ft_strlen(linst->raw)] = '\"';
	return (CW_SUCCESS);
}

/*
** Simply translate a literal.
** This is, in fact, a substep of insts translation.
*/

int			cw_asm_translate_literal(t_cw_asm *state, t_cw_linst *linst)
{
	int		i_lit;
	char	bck;
	int		type;
	int		i_space;

	i_lit = cw_asm_skip_spaces_index(linst, 0);
	if (i_lit != '.')
		return (CW_SUCCESS);
	i_space = i_lit;
	while (linst->raw[i_space] && !ft_isblank(linst->raw[i_space]))
		i_space++;
	bck = linst->raw[i_space];
	linst->raw[i_space] = '\0';
	type = cw_literal_get_type(&linst->raw[i_lit]);
	linst->raw[i_space] = bck;
	if (type == CW_LITERAL_TYPE_NONE)
		return (CW_ASM_ERROR_UNKNOWN_LITERAL);
	return (translate_literal2(state, linst, type, i_space));
}
