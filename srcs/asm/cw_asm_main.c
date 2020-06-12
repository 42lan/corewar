#include "libft.h"

#include "cw_errors.h"
#include "cw_asm.h"

int			main2(t_cw_asm_options *opt)
{
	(void)opt;
	ft_printf("{bold}{purple}TODO{}\n");
	return (CW_ERROR_BAD_DEVELOPPER);
}

int			main(int argc, char **argv)
{
	int rst;
	t_cw_asm_options	*opt;

	if (!(opt = cw_asm_options_create(argc, argv)))
		return (cw_asm_error(CW_ERROR_ASM_CREATING_OPTIONS));
	rst = opt->error;
	if (rst >= 0)
	{
		rst = main2(opt);
	}
	cw_asm_options_destroy(&opt);
	return (cw_asm_error(rst));
}
