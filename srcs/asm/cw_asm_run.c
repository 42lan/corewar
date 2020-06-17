#include "cw_asm.h"

/*
** Default main algorithm for asm:
** input -> translate -> assemble -> output
*/

int				cw_asm_run(t_cw_asm *state)
{
	int		rst;

ft_printf("{bold}{blue}input:\n");
	if ((rst = cw_asm_input(state)) < 0)
		return (rst);
ft_printf("{bold}{blue}translate:\n");
	if ((rst = cw_asm_translate(state)) < 0)
		return (rst);
ft_printf("{bold}{blue}assemble:\n");
	if ((rst = cw_asm_assemble(state)) < 0)
		return (rst);
ft_printf("{bold}{blue}output:\n");
	if ((rst = cw_asm_output(state)) < 0)
		return (rst);
ft_printf("{bold}{blue}done.\n");
	return (rst);
}
