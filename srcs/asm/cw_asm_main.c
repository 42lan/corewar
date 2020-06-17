/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:21:56 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:21:57 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cw_errors.h"
#include "cw_asm.h"

int			main(int argc, char **argv)
{
	int rst;
	t_cw_asm	*state;

	if (!(state = cw_asm_create()))
		return (cw_asm_error(CW_ERROR_MALLOC_FAILED));
	rst = cw_asm_options_parse(state->options, argc, argv);
	if (rst >= 0)
		rst = cw_asm_run(state);
	cw_asm_destroy(&state);
	return (cw_asm_error(rst));
}
