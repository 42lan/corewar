/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_linst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:20:30 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 18:20:33 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_LINST_H
# define CW_LINST_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "cw_literal.h"
# include "cw_inst.h"

/*
** t_cw_linst:
**
** Store an instruction read from a file.
** This correspond to a line, and can be of several kind.
**
** raw: raw string containing the corresponding line.
** label: optional label of the line. Exclusive with literal.
** literal: Instructions starting by ".". Exclusive with label and inst.
** inst: Op instructions. Exclusive with literal.
** offset: offset in the binary code.
*/

typedef struct s_cw_linst	t_cw_linst;
struct						s_cw_linst
{
	char				*raw;
	char				*label;
	t_cw_literal		*literal;
	t_cw_inst			*inst;
	uint32_t			offset;
};

void						cw_linst_default(t_cw_linst *linst);
void						cw_linst_clean(t_cw_linst *linst);

/*
** Helpers:
*/

int							cw_linst_size(t_cw_linst *linst);
void						cw_linst_write(t_cw_linst *linst,
											unsigned char *out);

#endif
