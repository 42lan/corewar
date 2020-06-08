#ifndef CW_OP_H
# define CW_OP_H

# include "libft_types.h"

/*
** t_cw_argtype:
**
** Represent the possible types of ops's arguments.
*/

typedef int				t_cw_arg_type;

# define T_REG 1
# define T_DIR 2
# define T_IND 4
# define T_LAB 8

# define CW_T_REG T_REG
# define CW_T_DIR T_DIR
# define CW_T_IND T_IND
# define CW_T_LAB T_LAB

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

typedef unsigned char	t_cw_opcode;

typedef struct s_cw_op	t_cw_op;
struct					s_cw_op
{
	char				*name;
	unsigned int		arg_count;
	t_cw_arg_type		arg_types[3];
	t_cw_opcode			opcode;
	unsigned int		cycles;
	char				*desc;
	t_bool				has_coding_byte;
	t_bool				has2;
};

# define CW_OP_COUNT 16

const t_cw_op			*cw_op_list(void);

/*
** t_cw_coding_code:
**
** An uint2 number, present in the coding byte.
** Represent the type of the arguments of the op.
*/

typedef unsigned char	t_cw_coding_code;

# define CW_REG_CODE 1
# define CW_DIR_CODE 2
# define CW_IND_CODE 3

/*
** t_cw_coding_byte:
**
** Some op have a byte used to describe what are it's arguments.
** It is composed of up to 3 t_cw_coding_code, packed to the left of the byte.
*/

typedef unsigned char	t_cw_coding_byte;

# define CW_IND_SIZE 2
# define CW_REG_SIZE 4
# define CW_DIR_SIZE CW_REG_SIZE

t_cw_coding_code		cw_op_get_coding_code(t_cw_arg_type type);
void					cw_op_get_coding_codes(t_cw_coding_code *out3,
											t_cw_coding_byte coding_byte);

t_cw_arg_type			cw_op_get_arg_type(t_cw_coding_code code);
void					cw_op_get_arg_types(t_cw_arg_type *out3,
											t_cw_coding_byte coding_byte);
t_cw_coding_byte		cw_op_get_coding_byte(t_cw_arg_type type, int index);
t_cw_coding_byte		cw_op_get_full_coding_byte(t_cw_arg_type *type3);

#endif
