/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_literal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:20:37 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 19:01:48 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_LITERAL_H
# define CW_LITERAL_H

/*
** t_cw_literal
**
** type: literal type, like name or comment.
** value: the value given as parameter for the literal.
*/

# define CW_LITERAL_NAME ".name"
# define CW_LITERAL_COMMENT ".comment"
# define CW_LITERAL_INT8 ".int8"
# define CW_LITERAL_INT16 ".int16"
# define CW_LITERAL_INT32 ".int32"
# define CW_LITERAL_PADDING ".padding"

# define CW_LITERAL_TYPE_NONE 0
# define CW_LITERAL_TYPE_NAME 1
# define CW_LITERAL_TYPE_COMMENT 2
# define CW_LITERAL_TYPE_INT8 10
# define CW_LITERAL_TYPE_INT16 11
# define CW_LITERAL_TYPE_INT32 12
# define CW_LITERAL_TYPE_PADDING 13

typedef struct s_cw_literal	t_cw_literal;
struct						s_cw_literal
{
	int				type;
	char			*value;
};

t_cw_literal				*cw_literal_create(int type, char *value);
void						cw_literal_destroy(t_cw_literal **literal);

int							cw_literal_get_type(const char *instr);
int							cw_literal_size(t_cw_literal *literal);
void						cw_literal_write(t_cw_literal *literal,
										unsigned char *out);

#endif
