#ifndef CW_ASM_H
# define CW_ASM_H

# include "libft.h"

# include "cw_errors.h"

# include "cw_champion.h"
# include "cw_linst.h"
# include "cw_asm_options.h"

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

t_cw_asm		*cw_asm_create(void);
void			cw_asm_destroy(t_cw_asm **state);

/*
** Errors:
*/

int				cw_asm_error(int code);

/*
** Main asm algorithm:
*/

int				cw_asm_run(t_cw_asm *state);

int				cw_asm_input(t_cw_asm *state);
int				cw_asm_translate(t_cw_asm *state);
int				cw_asm_assemble(t_cw_asm *state);
int				cw_asm_output(t_cw_asm *state);

#endif
