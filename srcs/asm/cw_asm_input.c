/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:21:52 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:45:27 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Same as cw_asm_input() but from an explicitely given fd.
*/

int				cw_asm_input_fd(t_cw_asm *state, int fd)
{
	int			rst;
	char		*line;
	t_cw_linst	*linst;
	
	rst = CW_ASM_ERROR_MALFORMED_FILE;
	while ((rst = ft_readtonl(fd, &line, 4096)))
	{
		if (ft_strpopnls(line) != 1
			|| !(linst = ft_array_newitem(state->linsts)))
		{
			ft_strdel(&line);
			return (CW_ASM_ERROR_MALFORMED_FILE);
		}
		linst->raw = line;
		line = NULL;
		linst = NULL;
		if (state->linsts->item_count > 0xFFFF)
			return (CW_ASM_ERROR_MALFORMED_FILE);
	}
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
