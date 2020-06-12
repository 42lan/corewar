/*
** t_cw_asm_options:
**
** Options read by asm.
** error: what error occured while parsing the options.
** in_file: .s source file to convert to binary.
** out_file: .cor file to output in binary.
*/

typedef struct s_cw_asm_options	t_cw_asm_options;
struct							s_cw_asm_options
{
	int			error;
	const char	*in_file;
	const char	*out_file;
};

t_cw_asm_options				*cw_asm_options_create(int argc, char **argv);
void							cw_asm_options_destroy(t_cw_asm_options **opt);

char							*cw_asm_default_out_file(const char *in_file);
