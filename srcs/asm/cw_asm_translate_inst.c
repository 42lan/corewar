#include "cw_asm.h"

/*
** Translate an inst. This is in fact a substep if insts translation.
*/

int			cw_asm_translate_inst(t_cw_asm *state, t_cw_linst *linst)
{
	int		i_op;
	int		i_arg;

	i_op = cw_asm_skip_label_index(linst);
	i_op = cw_asm_skip_spaces_index(linst, i_op);
	i_arg = cw_asm_spaces_index(linst, i_op);
	ft_printf("{purple}TODO: translate_int\n");
	(void)i_arg;
	(void)state;
	(void)linst;
	return (CW_SUCCESS);
}
