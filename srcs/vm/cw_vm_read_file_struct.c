/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_read_file_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 01:59:09 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/07 02:07:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_player.h"

/*
** cw_vm_read_champion_name() reads next 128 bytes `.cor` file, retreives
** champion name and store it in t_cw_champion
*/

int					cw_vm_read_champion_name(int fd, t_cw_player *player)
{
	char			name[CW_PROG_NAME_LENGTH + 1];

	if (read(fd, name, CW_PROG_NAME_LENGTH) != CW_PROG_NAME_LENGTH)
	{
		ft_dprintf(2, "{RED}ERROR READ CHAMPION NAME\n{}");
		return (CW_VM_READ_ERROR);
	}
	name[ft_strlen(name)] = '\0';
	if (!(player->champion->name = ft_strdup(name)))
	{
		ft_dprintf(2, "{red}ERROR MALLOC FAILED\n{}");
		return (CW_ERROR_MALLOC_FAILED);
	}
	return (CW_SUCCESS);
}

/*
** cw_vm_read_champion_null() reads next 4 bytes `.cor` and look if
** the name or comment is not too long
*/

int					cw_vm_read_champion_null(int fd, char *part)
{
	char			str[CW_CHAMPION_NULL];

	if (read(fd, str, CW_CHAMPION_NULL) != CW_CHAMPION_NULL)
	{
		ft_dprintf(2, "{RED}ERROR READ CHAMPION NULL\n{}");
		return (CW_VM_READ_ERROR);
	}
	if (ft_memcmp(str, "\0\0\0\0", CW_CHAMPION_NULL) != 0)
	{
		ft_dprintf(2, "{red}%s IS TOO LONG\n{}", part);
		return (CW_VN_ERROR_NAME_TOO_LONG);
	}
	return (CW_SUCCESS);
}

/*
** cw_vm_read_exec_code_len() reads next 4 bytes representing the size
** of champion's executable code
*/

int					cw_vm_read_exec_code_len(int fd, t_cw_player *player)
{
	int				i;
	int32_t			code_len_int;
	unsigned char	code_len[4];

	i = -1;
	if (read(fd, code_len, CW_EXEC_CODE_LEN) != CW_EXEC_CODE_LEN)
	{
		ft_dprintf(2, "{RED}ERROR READ CHAMPION EXEC CODE LEN\n{}");
		return (CW_VM_READ_ERROR);
	}
	code_len_int = ft_bigendian32_read(code_len);
	player->champion->code_len = code_len_int;
	return (CW_SUCCESS);
}

/*
** cw_vm_read_champion_comment() reads next 2048 bytes representnig champions
** comment
*/

int					cw_vm_read_champion_comment(int fd, t_cw_player *player)
{
	int				i;
	char			comment[CW_COMMENT_LENGTH + 1];

	i = -1;
	if (read(fd, comment, CW_COMMENT_LENGTH) != CW_COMMENT_LENGTH)
	{
		ft_dprintf(2, "{RED}ERROR READ CHAMPION COMMENT\n{}");
		return (CW_VM_READ_ERROR);
	}
	comment[ft_strlen(comment)] = '\0';
	if (!(player->champion->comment = ft_strdup(comment)))
	{
		ft_dprintf(2, "{red}ERROR MALLOC FAILED\n{}");
		return (CW_ERROR_MALLOC_FAILED);
	}
	return (CW_SUCCESS);
}

/*
** cw_vm_read_champion_exec_code() read the last part of the file which is
** executable code and check if it overflows
*/

int					cw_vm_read_champion_exec_code(int fd, t_cw_player *player)
{
	int				i;
	unsigned char	*exec_code;

	i = -1;
	if (!(exec_code = ft_memalloc(sizeof(exec_code) * player->champion->code_len)))
	{
		ft_dprintf(2, "{red}ERROR MALLOC FAILED\n{}");
		return (CW_ERROR_MALLOC_FAILED);
	}
	if (read(fd, exec_code, player->champion->code_len) != player->champion->code_len)
	{
		ft_dprintf(2, "{RED}ERROR READ CHAMPION EXEC CODE\n{}");
		return (CW_VM_READ_ERROR);
	}
	player->champion->code = exec_code;
	if ((read(fd, NULL, 1)) != 0)
	{
		ft_dprintf(2, "{RED}ERROR READ CHAMPION EXEC CODE OVERFLOW\n{}");
		return (CW_VM_READ_ERROR);
	}
	return (CW_SUCCESS);
}
