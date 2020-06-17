#include <stdlib.h>

#include "libft.h"

#include "cw_literal.h"

/*
** Create a literal.
*/

t_cw_literal	*cw_literal_create(int type, char *value)
{
	t_cw_literal	*literal;

	if (!(literal = malloc(sizeof(t_cw_literal))))
		return (NULL);
	literal->type = type;
	if (!(literal->value = ft_strdup(value)))
	{
		free(literal);
		return (NULL);
	}
	return (literal);
}

/*
** Destroy a literal.
*/

void			cw_literal_destroy(t_cw_literal **literal)
{
	free((*literal)->value);
	free(*literal);
	*literal = NULL;
}

/*
** Get the type of a literal.
*/

int				cw_literal_get_type(const char *instr)
{
	if (ft_strcmp(instr, CW_LITERAL_NAME) == 0)
		return (CW_LITERAL_TYPE_NAME);
	if (ft_strcmp(instr, CW_LITERAL_COMMENT) == 0)
		return (CW_LITERAL_TYPE_COMMENT);
	if (ft_strcmp(instr, CW_LITERAL_INT8) == 0)
		return (CW_LITERAL_TYPE_INT8);
	if (ft_strcmp(instr, CW_LITERAL_INT16) == 0)
		return (CW_LITERAL_TYPE_INT16);
	if (ft_strcmp(instr, CW_LITERAL_INT32) == 0)
		return (CW_LITERAL_TYPE_INT32);
	if (ft_strcmp(instr, CW_LITERAL_PADDING) == 0)
		return (CW_LITERAL_TYPE_PADDING);
	return (CW_LITERAL_TYPE_NONE);
}

/*
** Get a literal size in code.
*/

int				cw_literal_size(t_cw_literal *literal)
{
	if (literal->type == CW_LITERAL_TYPE_INT8)
		return (1);
	if (literal->type == CW_LITERAL_TYPE_INT16)
		return (2);
	if (literal->type == CW_LITERAL_TYPE_INT32)
		return (4);
	if (literal->type == CW_LITERAL_TYPE_PADDING)
		return (ft_atoi(literal->value));
	return (0);
}

/*
** Write a literal to its binary representation.
*/

void			cw_literal_write(t_cw_literal *literal, unsigned char *out)
{
	if (literal->type == CW_LITERAL_TYPE_INT8)
		out[0] = ft_atoi(literal->value);
	if (literal->type == CW_LITERAL_TYPE_INT16)
		ft_bigendian16_write((unsigned char*)out, ft_atoi(literal->value));
	if (literal->type == CW_LITERAL_TYPE_INT32)
		ft_bigendian32_write((unsigned char*)out, ft_atoi(literal->value));
	if (literal->type == CW_LITERAL_TYPE_PADDING)
		ft_bzero(out, ft_atoi(literal->value));
}				
