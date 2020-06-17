/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asmr_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:25:45 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 20:05:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

static char		*get1(int error)
{
	if (error == CW_ASMR_NAME_TRUNCATED)
		return ("Champion name too long, will be truncated.");
	if (error == CW_ASMR_NAME_MISSING)
		return ("Champion name empty.");
	if (error == CW_ASMR_COMMENT_TRUNCATED)
		return ("Champion comment too long, will be truncated.");
	if (error == CW_ASMR_COMMENT_MISSING)
		return ("Champion comment empty.");	
	if (error == CW_ASMR_CODE_TOO_LONG)
		return ("Champion code may be too long.");
	if (error == CW_ASMR_SYNTAX)
		return ("Syntax error.");
	if (error == CW_ASMR_UNEXPECTED)
		return ("Unexpected token.");
	if (error == CW_ASMR_STRING_INVALID)
		return ("Invalid string.");
	if (error == CW_ASMR_INT_INVALID)
		return ("Invalid integer.");
	if (error == CW_ASMR_LABEL_DUPLICATE)
		return ("Label is already defined.");
	if (error == CW_ASMR_LABEL_MISSING)
		return ("Undefined label.");
	if (error == CW_ASMR_LITERAL_UNKNOWN)
		return ("Unknown literal.");
	return (NULL);
}

static char		*get2(int error)
{
	if (error == CW_ASMR_OP_UNKNOWN)
		return ("Unknown op.");
	if (error == CW_ASMR_ARG_COUNT)
		return ("Wrong argument counts.");
	if (error == CW_ASMR_ARG_TYPE)
		return ("Wrong argument types.");
	return (NULL);
}

static void		details(t_cw_linst *linst, int error)
{
	const t_cw_op		*op;

	if (linst->inst)
	{
		op = cw_op_get(linst->inst->opc);
		if (error == CW_ASMR_ARG_COUNT)
			ft_dprintf(2, "Op %s takes %d arguments.", op->name, op->arg_count);
	}
}

/*
** Print an error message to stderr, according to the given number.
** This is only for asmr errors.
*/

void			cw_asmr_msg(int error, t_cw_linst *linst)
{
	char	*msg1;
	char	*msg2;

	(void)linst;
	(void)error;
	if ((msg1 = get1(error)) != NULL)
		ft_dprintf(2, "%s\n", msg1);
	if ((msg2 = get2(error)) != NULL)
		ft_dprintf(2, "%s\n", msg2);
	details(linst, error);
	if (!msg1 && !msg2)
		ft_dprintf(2, "%d\n", error);
}
