#include "cw_asm.h"

/*
** Same as cw_asm_input() but from an explicitely given fd.
*/

int				cw_asm_input_fd(t_cw_asm *state, int fd)
{
	int		rst;

	rst = CW_SUCCESS;
	(void)state;
	(void)fd;
	ft_printf("{cyan}TODO: cw_asm_input_fd\n");
	return (rst);
}

/*
** asm input stage:
** The linsts list is filled with line informations
*/

int				cw_asm_input(t_cw_asm *state)
{
	int		rst;
	int		fd;
	
	if (state->options->in_file == NULL)
		return (cw_asm_input_fd(state, 0));
	if ((fd = open(state->options->in_file, O_RDONLY)) < 0)
		return (CW_ERROR_OPENING_INPUT_FILE);
	rst = cw_asm_input_fd(state, fd);
	close(fd);
	return (rst);
}
