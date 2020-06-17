#include "libft.h"

#include "cw_op.h"

/*
** Get an op from its op code.
** The returned pointer must not be freed.
*/

const t_cw_op			*cw_op_get(t_cw_opc opc)
{
	const t_cw_op	*ops;

	if (opc < CW_OP_MIN || opc >= CW_OP_MAX)
		return (NULL);
	ops = cw_op_list();
	return (&ops[opc - CW_OP_MIN]);
}

/*
** Get an op from its name.
** The returned pointer must not be freed.
*/

const t_cw_op			*cw_op_get_from_name(const char *name)
{
	const t_cw_op	*ops;
	int				i_op;

	ops = cw_op_list();
	i_op = 0;
	while (ops[i_op].name != NULL)
	{
ft_printf("{grey} >< %s\n", ops[i_op].name);//
		if (ft_strcmp(ops[i_op].name, name) == 0)
			return (&ops[i_op]);
		i_op++;
	}
	return (NULL);	
}
