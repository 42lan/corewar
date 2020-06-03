#ifndef CW_OP_H
# define CW_OP_H

# include "libft_types.h"

/*
** t_cw_argtype:
**
** Represent the possible types of ops's arguments.
*/

typedef int				t_cw_arg_type;

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

/*
** t_cw_op:
**
** Represent an implemented operation/instruction that the machine can execute.
**
** name: The instruction name as it is in the champion source code.
** arg_count: How many arguments does this op take.
** arg_types: Array of argument types.
** code: Code used in the binary code to represent this op.
** cycles: How much time is necessary to execute this op.
** desc: Longer human-readable name for this op.
** has_coding_byte: Does this op have a byte used to tell about
** the arguments's encoding.
** has2: ?
*/

typedef struct s_cw_op	t_cw_op;
struct					s_cw_op
{
	char				*name;
	unsigned int		arg_count;
	t_cw_arg_type		arg_types[3];
	char				code;
	unsigned int		cycles;
	char				*desc;
	t_bool				has_coding_byte;
	t_bool				has2;
};

const t_cw_op			*cw_op_list();

#endif
