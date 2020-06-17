/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:17:34 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 20:04:41 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_ASM_H
# define CW_ASM_H

# include "libft.h"

# include "cw_errors.h"

# include "cw_champion.h"
# include "cw_linst.h"
# include "cw_asm_options.h"

# define CW_COMMENT_CHAR '#'
# define CW_COMMENT_CHAR2 ';'
# define CW_LABEL_CHAR ':'
# define CW_DIRECT_CHAR '%'
# define CW_SEP_CHAR ','
# define CW_LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

/*
** t_cw_asm:
**
** Structure storing the state of the asm program.
**
** has_error: store if an error occured that didnt requiere to exit.
** options: represent options given to the program.
** linsts: store de data read and translated.
** code_len: code_len computed at the translation stage.
** champion: the champion output.
*/

typedef struct s_cw_asm	t_cw_asm;
struct					s_cw_asm
{
	int					has_error;
	t_cw_asm_options	*options;
	t_array				*linsts;
	uint32_t			code_len;
	t_cw_champion		*champion;
};

t_cw_asm				*cw_asm_create(void);
void					cw_asm_destroy(t_cw_asm **state);

/*
** Errors:
*/

int						cw_asm_error(int code);
int						cw_asm_error_msg(int code);
int						cw_asmr(int error, int index, t_cw_linst *linst);
void					cw_asmr_msg(int error, t_cw_linst *linst);

/*
** Main asm algorithm:
*/

int						cw_asm_run(t_cw_asm *state);

int						cw_asm_input(t_cw_asm *state);
int						cw_asm_translate(t_cw_asm *state);
int						cw_asm_translate_labels(t_cw_asm *state);
int						cw_asm_translate_insts(t_cw_asm *state);
int						cw_asm_translate_insts_labels(t_cw_asm *state);
int						cw_asm_assemble(t_cw_asm *state);
int						cw_asm_output(t_cw_asm *state);

/*
** Helpers:
*/

int						cw_asm_get_label_index(t_cw_asm *state, char *name);
int						cw_asm_get_label_offset(t_cw_asm *state, int index);
int						cw_asm_nothing_at_end(t_cw_asm *state,
												t_cw_linst *linst,
												int index);
int						cw_asm_dismember_string(t_cw_asm *state,
												t_cw_linst *linst,
												int index);

int						cw_asm_skip_label_index(t_cw_linst *linst);
int						cw_asm_skip_spaces_index(t_cw_linst *linst, int index);
int						cw_asm_spaces_index(t_cw_linst *linst, int index);
int						cw_asm_skip_alnums_index(t_cw_linst *linst, int index);
int						cw_asm_argend_index(t_cw_linst *linst, int index);
int						cw_asm_nextarg_index(t_cw_linst *linst, int index);

int						cw_asm_translate_literal(t_cw_asm *state,
													t_cw_linst *linst);
int						cw_asm_translate_inst(t_cw_asm *state,
												t_cw_linst *linst);

#endif
