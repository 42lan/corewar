#include "cw_asm.h"

/*
** Asm algorithm: Output stage.
** The internal champion is outputed according to the options.
*/

int				cw_asm_output(t_cw_asm *state)
{
	int		rst;

	rst = cw_champion_save_to_file(state->champion, state->options->out_file);
	return (rst);
}

