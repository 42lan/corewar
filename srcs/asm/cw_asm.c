#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "cw_asm.h"

/*
** Create a default t_cw_asm.
*/

t_cw_asm		*cw_asm_create(void)
{
	t_cw_asm	*state;

	if (!(state = ft_memalloc(sizeof(t_cw_asm))))
		return (NULL);
	state->has_error = 0;
	state->code_len = 0;
	if (!(state->options = cw_asm_options_create())
		|| (cw_champion_create(&state->champion) != 0)
		|| !(ft_array_new(sizeof(t_cw_linst), 8)))
	{
		cw_asm_destroy(&state);
	}
	return (state);
}

/*
** Destroy a t_cw_asm.
*/

void			cw_asm_destroy(t_cw_asm **state)
{
	int			i_linst;

	ft_printf("---- before opt destroy\n");
	cw_asm_options_destroy(&((*state)->options));
	ft_printf("---- before linst cleanup\n");
	i_linst = 0;
	while (i_linst < (*state)->linsts->item_count)
	{
		cw_linst_clean((t_cw_linst*)ft_array_at((*state)->linsts, i_linst));
		i_linst++;
	}
	ft_array_del(&(*state)->linsts);
	cw_champion_destroy(&((*state)->champion));
	free(*state);
	*state = NULL;
}








