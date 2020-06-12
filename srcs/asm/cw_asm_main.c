#include "libft.h"

#include "cw_errors.h"
#include "cw_asm.h"

int			main2(t_cw_asm_options *opt)
{
	int				rst;
	t_cw_champion	*champ;

	if ((rst = cw_champion_create(&champ)) < 0)
		return (rst);
	if (rst > 0)
	{
		rst = cw_asm_from_file(champ, opt->in_file);
		if (rst > 0)
			rst = cw_champion_save_to_file(champ, opt->out_file);
	}
	cw_champion_destroy(&champ);
	return (rst);
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
