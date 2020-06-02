#include <stdlib.h>

#include "cw_champion.h"
#include "cw_errors.h"

/*
** Create a champion.
*/

int		cw_champion_create(t_cw_champion **champion)
{
	if (!(*champion = malloc(sizeof(t_cw_champion))))
		return (CW_ERROR_MALLOC_FAILED);
	(*champion)->name = NULL;
	(*champion)->comment = NULL;
	(*champion)->code_len = 0;
	(*champion)->code = NULL;
	return (CW_SUCCESS);
}

/*
** Destroy a champion.
*/

void	cw_champion_destroy(t_cw_champion **champion)
{
	free((void*)(*champion)->name);
	free((void*)(*champion)->comment);
	free((void*)(*champion)->code);
	free((void*)*champion);
	*champion = NULL;
}
