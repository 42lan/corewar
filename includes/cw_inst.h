#ifndef CW_INST_H
# define CW_INST_H

# include "cw_op.h"

/*
** t_cw_inst:
**
** Instruction.
** Represent an instance of an op, with determined arguments.
** opcode: The opcode corresponding to an op.
** args_count: How many args does this op have.
** args: Unresolved args, not the real values.
** types: Types of each argument in args.
*/

typedef struct s_cw_inst	t_cw_inst;
struct						s_cw_inst
{
	t_cw_opcode			opcode;
	t_bool				has_coding_byte;
	unsigned int		args_count;	
	int					args[3];		
	t_cw_arg_type		types[3];
};

int							cw_inst_write(t_cw_inst *inst, char *dst);

/*
** Change "arena" and "arena_size" by just 1 pointer to the arena structure.
** You can fill an "inst" by looking in the op list at index "opcode - 1".
*/
int							cw_inst_fill(t_cw_inst *dst_inst,
										const char *arena,
										unsigned int arena_size,
										unsigned int pc);
int							cw_inst_fill(t_cw_inst *dst_inst,
										const char *arena,
										unsigned int arena_size,
										unsigned int pc);

#endif
