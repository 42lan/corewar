/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:22:14 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 20:30:10 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

/*
** Asm algorithm: Output stage.
** The internal champion is outputed according to the options.
*/

int				cw_asm_output(t_cw_asm *state)
{
	int		rst;

	if (!state->champion->name)
		cw_asmr(CW_ASMR_NAME_MISSING, -1, NULL);
	else if (ft_strlen(state->champion->name) > CW_PROG_NAME_LENGTH)
		cw_asmr(CW_ASMR_NAME_TRUNCATED, -1, NULL);
	if (!state->champion->comment)
		cw_asmr(CW_ASMR_COMMENT_MISSING, -1, NULL);
	else if (ft_strlen(state->champion->comment) > CW_COMMENT_LENGTH)
		cw_asmr(CW_ASMR_COMMENT_TRUNCATED, -1, NULL);
	if (state->champion->code_len > CW_CHAMP_MAX_SIZE)
		cw_asmr(CW_ASMR_CODE_TOO_LONG, -1, NULL);
	if (state->options->out_file)
		ft_printf("Writing output program to %s\n", state->options->out_file);
	rst = cw_champion_save_to_file(state->champion, state->options->out_file);
	return (rst);
}
