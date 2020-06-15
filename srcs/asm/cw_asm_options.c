#include <stdlib.h>

#include "cw_errors.h"
#include "cw_asm_options.h"

/*
** Create an asm options structure.
*/

t_cw_asm_options	*cw_asm_options_create(void)
{
	t_cw_asm_options	*opt;

	if (!(opt = malloc(sizeof(t_cw_asm_options))))
		return (NULL);
	opt->in_file = NULL;
	opt->out_file = NULL;
	return (opt);
}

/*
** Destroy an asm options structure.
*/

void				cw_asm_options_destroy(t_cw_asm_options **opt)
{
	free((void*)((*opt)->out_file));
	free(*opt);
	*opt = NULL;
}

/*
** Fill an asm options structure from command line arguments.
*/

int					cw_asm_options_parse(t_cw_asm_options *opt,
											int argc, char **argv)
{
	if (argc >= 3)
		return (CW_ASM_ERROR_UNKNOWN_OPTION);
	if (argc <= 1)
		return (CW_SUCCESS);
	opt->in_file = argv[1];
	opt->out_file = cw_asm_default_out_file(argv[1]);
	return (CW_SUCCESS);
}
