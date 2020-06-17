/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:21:30 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:49:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "cw_asm.h"

/*
** Create a default t_cw_asm.
*/

t_cw_asm		*cw_asm_create(void)
{
	t_cw_asm	*state;

	if (!(state = ft_memalloc(sizeof(t_cw_asm))))
		return (NULL);
	state->has_error = 0;
	state->code_len = 0;
	if (!(state->options = cw_asm_options_create())
		|| (cw_champion_create(&state->champion) != 0)
		|| !(state->linsts = ft_array_new(sizeof(t_cw_linst), 8)))
	{
		cw_asm_destroy(&state);
	}
	return (state);
}

/*
** Destroy a t_cw_asm.
*/

void			cw_asm_destroy(t_cw_asm **state)
{
	int			i_linst;
	t_cw_linst	*inst;

	cw_asm_options_destroy(&((*state)->options));
	i_linst = 0;
	if ((*state)->linsts != NULL)
		while (i_linst < (*state)->linsts->item_count)
		{
			inst = (t_cw_linst*)ft_array_at((*state)->linsts, i_linst);
			cw_linst_clean(inst);
			i_linst++;
		}
	ft_array_del(&(*state)->linsts);
	cw_champion_destroy(&((*state)->champion));
	free(*state);
	*state = NULL;
}
