/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:20 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/18 05:44:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Default main algorithm for asm:
** input -> translate -> assemble -> output
*/

int				cw_asm_run(t_cw_asm *state)
{
	int		rst;

	if ((rst = cw_asm_input(state)) < 0)
		return (rst);
	if ((rst = cw_asm_translate(state)) < 0)
		return (rst);
	if ((rst = cw_asm_assemble(state)) < 0)
		return (rst);
	if ((rst = cw_asm_output(state)) < 0)
		return (rst);
	return (rst);
}
