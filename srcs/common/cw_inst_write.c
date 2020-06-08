#include "cw_inst.h"

/*
** Write a single argument to a byte array.
** Return how many bytes were written.
*/

static int	cw_inst_write_arg(int arg, t_cw_arg_type type, const char *dst)
{
	int		arg_length;

	arg_len = cw_op_get_arg_len(type);
	if (arg_len == sizeof(uint16))
		ft_bigendian16_write(dst, arg);
	else
		ft_bigendian32_write(dst, arg);
	return (arg_len);
}

/*
** Encode an t_inst to a byte array.
** 
** Returns how many bytes were written.
*/

int			cw_inst_write(t_cw_inst *inst, char *dst)
{
	int		i_dst;

	dst[i_dst] = inst->opcode;
	i_dst += 1;
	if (inst->has_coding_byte)
	{
		dst[i_dst] = cw_op_get_coding_byte
		i_dst += 1;	
	}
	if (inst->args_count > 0)
		i_dst += cw_inst_write_arg(inst->args[0], inst->types[0], &dst[i_dst]);
	if (inst->args_count > 1)
		i_dst += cw_inst_write_arg(inst->args[1], inst->types[1], &dst[i_dst]);
	if (inst->args_count > 2)
		i_dst += cw_inst_write_arg(inst->args[2], inst->types[2], &dst[i_dst]);
	return (i_dst);
}
