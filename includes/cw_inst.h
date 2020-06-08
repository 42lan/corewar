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
** args_types: Types of each argument in args.
*/

typedef struct s_cw_inst	t_cw_inst;
struct						s_cw_inst
{
	t_cw_opcode			opcode;
	unsigned int		args_count;	
	int					args[3];		
	t_cw_arg_type		args_types[3];
};

int							cw_inst_save(t_cw_inst *inst, const char *dst);
int							cw_inst_fill(t_cw_inst *dst_inst,
										const char *arena,
										unsigned int arena_size,
										unsigned int pc);
int							cw_inst_fill(t_cw_inst *dst_inst,
										const char *arena,
										unsigned int arena_size,
										unsigned int pc);

#endif
