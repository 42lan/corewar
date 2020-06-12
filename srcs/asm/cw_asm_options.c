#include <stdlib.h>

#include "cw_errors.h"
#include "cw_asm_options.h"

/*
** Create an asm options structure from command line arguments.
*/

t_cw_asm_options				*cw_asm_options_create(int argc, char **argv)
{
	t_cw_asm_options	*opt;

	if (!(opt = malloc(sizeof(t_cw_asm_options))))
		return (NULL);
	opt->error = 0;
	opt->in_file = NULL;
	opt->out_file = NULL;
	if (argc >= 3)
		opt->error = CW_ERROR_ASM_UNKNOWN_OPTION;
	if (opt->error != 0)
		return (opt);
	opt->in_file = argv[1];
	opt->out_file = cw_asm_default_out_file(argv[1]);
	return (opt);
}

/*
** Destroy an asm options structure.
*/

void							cw_asm_options_destroy(t_cw_asm_options **opt)
{
	free((void*)((*opt)->out_file));
	free(*opt);
	*opt = NULL;
}
