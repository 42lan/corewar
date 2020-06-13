#include <stdlib.h>

#include "cw_label.h"

/*
** Destroy a label.
*/

void			cw_label_destroy(t_cw_label **label)
{
	free(*label);
	*label = NULL;
}
