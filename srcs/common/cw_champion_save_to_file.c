#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

#include "cw_errors.h"
#include "cw_champion.h"

/*
** Save a champion to a file descriptor.
*/

int		cw_champion_save_to_fd(t_cw_champion *champion, int fd)
{
	char	tmp[4];

	ft_bigendian32_write((unsigned char *)tmp, CW_EXEC_MAGIC);
	if (write(fd, tmp, 4) < 0)
		return (CW_ERROR_WRITING_OUTPUT_FILE);
	if (write(fd, champion->name, CW_PROG_NAME_LENGTH) < 0)
		return (CW_ERROR_WRITING_OUTPUT_FILE);
	ft_bigendian32_write((unsigned char *)tmp, champion->code_len);
	if (write(fd, tmp, 4) < 0)
		return (CW_ERROR_WRITING_OUTPUT_FILE);
	if (write(fd, champion->comment, CW_COMMENT_LENGTH) < 0)
		return (CW_ERROR_WRITING_OUTPUT_FILE);
	if (write(fd, champion->code, champion->code_len) < 0)
		return (CW_ERROR_WRITING_OUTPUT_FILE);
	return (0);
}

/*
** Save a champion to a file.
** Use standard output if NULL is provided.
*/

int		cw_champion_save_to_file(t_cw_champion *champion, const char *file)
{
	int		rst;
	int		fd;

	if (file == NULL)
		return (cw_champion_save_to_fd(champion, 1));
	fd = open(file, O_WRONLY | O_CREAT);
	if (fd < 0)
		return (CW_ERROR_OPENING_OUTPUT_FILE);
	rst = cw_champion_save_to_fd(champion, fd);
	close(fd);
	return (rst);
}
