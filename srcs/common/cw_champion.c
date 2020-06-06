/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_champion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:39:55 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/07 01:37:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "cw_champion.h"
#include "cw_errors.h"
#include <unistd.h>

/*
** Create a champion.
*/

int					cw_champion_create(t_cw_champion **champion)
{
	if (!(*champion = malloc(sizeof(t_cw_champion))))
		return (CW_ERROR_MALLOC_FAILED);
	(*champion)->name = NULL;
	(*champion)->comment = NULL;
	(*champion)->code_len = 0;
	(*champion)->code = NULL;
	return (CW_SUCCESS);
}

/*
** Destroy a champion.
*/

void				cw_champion_destroy(t_cw_champion **champion)
{
	free((void*)(*champion)->name);
	free((void*)(*champion)->comment);
	free((void*)(*champion)->code);
	free((void*)*champion);
	*champion = NULL;
}

/*
** Dump a champion.
*/

static void			hex_dump(unsigned char *code, unsigned int code_len)
{
	unsigned int	i;
	unsigned char	buff[17];
	unsigned char	*pc;

	i = -1;
	pc = code;
	while (++i < code_len)
	{
		if ((i % 16) == 0)
		{
			(i != 0) ? ft_printf(" %s\n", buff) : 0;
			(i != 0) ? ft_printf("         ") : 0;
			/* ft_printf("{yellow}0x%06x:{}", i); */
		}
		(i % 2 == 0) ? ft_printf(" ") : 0;
		ft_printf("%02x", pc[i]);
		buff[i % 16] = ((!ft_isprint(pc[i]))) ? '.' : pc[i];
		buff[(i % 16) + 1] = '\0';
	}
	ft_printf("\n");
}

void				cw_champion_dump(t_cw_champion *champion)
{
	ft_printf("\n{blue}{bold}===== C H A M P I O N   D U M P ====={}\n");
	ft_printf("{bold}Name:{}     %s\n", champion->name);
	ft_printf("{bold}Comment:{}  %s\n", champion->comment);
	ft_printf("{bold}Code len:{} %d\n", champion->code_len);
	ft_printf("{bold}Code:{}    ");
	hex_dump(champion->code, champion->code_len);
}
