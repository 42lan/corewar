/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_translate_insts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:58 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:38:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

static int	translate(t_cw_asm *state, t_cw_linst *linst)
{
	int		rst;

	if ((rst = cw_asm_translate_literal(state, linst)) < 0)
		return (rst);
	if (linst->literal == NULL)
		if ((rst = cw_asm_translate_inst(state, linst)) < 0)
			return (rst);
	return (rst);
}

/*
** Asm algorithm: Translation stage:
** Translate the remaining linsts into inst when possible.
** This requieres labels to have been translated already.
*/

int			cw_asm_translate_insts(t_cw_asm *state)
{
	int			rst;
	t_cw_linst	*insts;
	int			i_linst;

	rst = CW_SUCCESS;
	insts = (t_cw_linst*)state->linsts->items;
	i_linst = 0;
	while (i_linst < state->linsts->item_count)
	{
		insts[i_linst].offset = state->code_len;
		if ((rst = translate(state, &insts[i_linst])) < 0)
			return (rst);
		state->code_len += cw_linst_size(&insts[i_linst]);
		i_linst++;
	}
	return (rst);
}
