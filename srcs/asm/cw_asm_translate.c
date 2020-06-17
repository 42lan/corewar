/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:50 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:22:52 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cw_asm.h"

/*
** Asm algorithm: Translation stage.
** The internal linsts items have their elements filled with
** data describing the instructions.
** The code_len is determined by all the instructions len.
*/

int				cw_asm_translate(t_cw_asm *state)
{
	int		rst;

ft_printf("{blue} translate_labels:\n");
	if ((rst = cw_asm_translate_labels(state)) < 0)
		return (rst);
ft_printf("{blue} translate_insts:\n");
	if ((rst = cw_asm_translate_insts(state)) < 0)
		return (rst);
ft_printf("{blue} translate_insts_labels:\n");
	if ((rst = cw_asm_translate_insts_labels(state)) < 0)
		return (rst);
	return (rst);
}
