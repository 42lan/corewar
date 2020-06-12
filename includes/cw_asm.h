#ifndef CW_ASM_H
# define CW_ASM_H

# include "cw_champion.h"

# include "cw_asm_options.h"

int				cw_asm_error(int code);

int				cw_asm_from_fd(t_cw_champion *champ, int fd);
int				cw_asm_from_file(t_cw_champion *champ, const char *in_file);


#endif
