/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:18:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:19:40 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_ASM_OPTIONS_H
# define CW_ASM_OPTIONS_H

/*
** t_cw_asm_options:
**
** Options read by asm.
** in_file: .s source file to convert to binary.
** out_file: .cor file to output in binary.
*/

typedef struct s_cw_asm_options	t_cw_asm_options;
struct							s_cw_asm_options
{
	const char	*in_file;
	const char	*out_file;
};

t_cw_asm_options				*cw_asm_options_create(void);
void							cw_asm_options_destroy(t_cw_asm_options **opt);

/*
** Options parsing:
*/

int								cw_asm_options_parse(t_cw_asm_options *opt,
														int argc, char **argv);
char							*cw_asm_default_out_file(const char *in_file);

#endif
