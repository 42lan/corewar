#ifndef CW_CHAMPION_H
# define CW_CHAMPION_H

# include "cw_vm_arena.h"

# define CW_EXEC_MAGIC			0xea83f3
# define CW_PROG_NAME_LENGTH	128
# define CW_CHAMPION_NULL		4
# define CW_EXEC_CODE_LEN		4
# define CW_COMMENT_LENGTH		2048
# define CW_CHAMP_MAX_SIZE		(CW_MEM_SIZE / 6)

/*
** t_cw_champion:
**
** Represent a corewar champion.
*/

typedef struct s_cw_champion	t_cw_champion;
struct							s_cw_champion
{
	char			*name;
	char			*comment;
	unsigned int	code_len;
	unsigned char	*code;
};

int								cw_champion_create(t_cw_champion **ch);
void							cw_champion_destroy(t_cw_champion **ch);
void							cw_champion_dump(t_cw_champion *ch);

/*
** Champion loading and saving:
*/

int								cw_champion_load_from_file(t_cw_champion *ch,
															const char *file);
int								cw_champion_save_to_file(t_cw_champion *ch,
															const char *file);

#endif
