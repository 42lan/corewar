#include "libft.h"

#include "cw_asm_options.h"

/*
** Give a file name to use for output.
** If the file ends in ".s" it become ".cor"
** otherwise, ".cor" is added at the end.
** If no file name is given, a default is provided.
*/

char							*cw_asm_default_out_file(const char *in_file)
{
	int		in_len;
	char	*out_file;	

	if (in_file == NULL)
		return (ft_strdup("out.cor"));
	in_len = ft_strlen(in_file);
	if (ft_strends(in_file, ".s"))
	{
		out_file = ft_strnew(in_len + 2);
		ft_strcpy(out_file, in_file);
		ft_strcpy(&out_file[in_len - 2], ".cor");
	}
	else
	{
		out_file = ft_strnew(in_len + 4);
		ft_strcpy(out_file, in_file);
		ft_strcpy(&out_file[in_len], ".cor");
	}
	return (out_file);
}
