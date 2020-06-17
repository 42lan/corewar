/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_translate_insts_labels.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:23:02 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:48:52 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Convert label types in an inst to indirect type.
*/

int			cw_asm_translate_inst_labels(t_cw_asm *state, t_cw_inst *inst,
											int inst_offset)
{
	unsigned int		i_arg;

	i_arg = 0;
	while (i_arg < inst->args_count)
	{
		if (inst->types[i_arg] & CW_T_LAB)
		{
			inst->types[i_arg] &= ~CW_T_LAB;
			inst->args[i_arg] = cw_asm_get_label_offset(state,
														(inst->args[i_arg]))
								- inst_offset;
		}
		i_arg++;
	}
	return (CW_SUCCESS);
}

/*
** Asm algorithm: Translation stage: insts labels
** Convert label types arguments if insts to indirects.
*/

int			cw_asm_translate_insts_labels(t_cw_asm *state)
{
	t_cw_linst	*insts;
	int			i_linst;

	insts = (t_cw_linst*)state->linsts->items;
	i_linst = 0;
	while (i_linst < state->linsts->item_count)
	{
		if (insts[i_linst].inst)
			cw_asm_translate_inst_labels(state, insts[i_linst].inst,
											insts[i_linst].offset);
		i_linst++;
	}
	return (CW_SUCCESS);
}
