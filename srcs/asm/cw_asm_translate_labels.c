/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_translate_labels.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:23:06 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:23:07 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Consider the linst is a label and translate it without checking.
*/

int			cw_asm_translate_label2(t_cw_asm *state, t_cw_linst *linst,
									int i_label)
{
	char		*label;

	if (!(label = ft_strcdup(&linst->raw[i_label], CW_LABEL_CHAR)))
		return (CW_ERROR_MALLOC_FAILED);
ft_printf("{cyan} just labelized '%s'\n", label);
	if (cw_asm_get_label_index(state, label) >= 0)
	{
		free(label);
		return (CW_ASM_ERROR_DUPLICATE_LABEL);
	}
	linst->label = label;
	return (CW_SUCCESS);
}

/*
** Try to translate a single linst to a label if ever it is one.
**
** We consider a label have been inputed if the last char is ':'.
*/

int			cw_asm_translate_label(t_cw_asm *state, t_cw_linst *linst)
{
	int		i_label;
	int		i_end;

	i_label = cw_asm_skip_spaces_index(linst, 0);
	i_end = i_label;
	while (linst->raw[i_end] && ft_strchr(CW_LABEL_CHARS, linst->raw[i_end]))
		i_end++;
ft_printf("{lime}??? %d %d %c\n", i_label, i_end, linst->raw[i_end]);
	if (linst->raw[i_end] != CW_LABEL_CHAR)
		return (CW_SUCCESS);
ft_printf("{lime}!!!\n");
	return (cw_asm_translate_label2(state, linst, i_label));
}

/*
** Asm algorithm: Translation stage: labels only
** Search labels and translate them, so they have an index
** wich can be used for the other translation steps,
** when an op use a label.
*/

int			cw_asm_translate_labels(t_cw_asm *state)
{
	int			rst;
	t_cw_linst	*linsts;
	int			i_linst;
	
	linsts = (t_cw_linst*)state->linsts->items;
	i_linst = 0;
	while (i_linst < state->linsts->item_count)
	{
		if ((rst = cw_asm_translate_label(state, &linsts[i_linst])) < 0)
			return (rst);
		i_linst++;
	}
	return (CW_SUCCESS);
}
