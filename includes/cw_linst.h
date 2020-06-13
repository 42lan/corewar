#ifndef CW_LINST_H
# define CW_LINST_H

# include "cw_literal.h"
# include "cw_label.h"
# include "cw_inst.h"

/*
** t_cw_linst:
**
** Store an instruction read from a file.
** This correspond to a line, and can be of several kind.
*/

# define CW_LINST_TYPE_RAW 0
# define CW_LINST_TYPE_LITERAL 1
# define CW_LINST_TYPE_LABEL 0
# define CW_LINST_TYPE_INST 0

typedef struct s_cw_linst	t_cw_linst;
struct						s_cw_linst
{
	int					type;
	union
	{
		char			*raw;
		t_cw_literal	*literal;
		t_cw_label		*label;
		t_cw_inst		*inst;
	};
	uint32_t			offset;
};

void						cw_linst_default(t_cw_linst *linst);
void						cw_linst_clean(t_cw_linst *linst);

#endif
