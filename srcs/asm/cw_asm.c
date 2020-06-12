#include <fcntl.h>

#include "libft.h"

#include "cw_asm.h"

/*
** Parse a champion from a file descriptor.
*/

int				cw_asm_from_fd(t_cw_champion *champ, int fd)
{
	(void)champ;
	(void)fd;
	//ft_strcpy(champ->name, "champion name");
	//champ->code_len = 0;
	//ft_strcpy(champ->comment, "the champion comment");
	//champ->code = NULL;
	return (0);
}

/*
** Parse a champion from a file.
** Use standard input if no file provided.
*/

int				cw_asm_from_file(t_cw_champion *champ, const char *in_file)
{
	int		fd;
	
	if (in_file == NULL)
		return (cw_asm_from_fd(champ, 0));
	if ((fd = open(in_file, O_RDONLY)) < 0)
		return (CW_ERROR_OPENING_INPUT_FILE);
	return (cw_asm_from_fd(champ, fd));
}


