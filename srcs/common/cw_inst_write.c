#include "libft.h"

#include "cw_inst.h"

/*
** Write a single argument to a byte array.
** Return how many bytes were written.
*/

static int	cw_inst_write_arg(t_cw_inst *inst, int i_arg, unsigned char *dst)
{
	int		arg_len;

	arg_len = cw_inst_arg_size(inst->opc, inst->types[i_arg]);
	if (arg_len == sizeof(int32_t))
		ft_bigendian32_write((unsigned char *)dst, (int32_t)inst->args[i_arg]);
	else if (arg_len == sizeof(int16_t))
		ft_bigendian16_write((unsigned char *)dst, (int16_t)inst->args[i_arg]);
	else if (arg_len == sizeof(char))
		((char *)dst)[0] = (char)inst->args[i_arg];
	return (arg_len);
}

/*
** Encode an t_inst to a byte array.
** 
** Returns how many bytes were written.
*/

int			cw_inst_write(t_cw_inst *inst, unsigned char *dst)
{
	int		i_dst;

	i_dst = 0;
	dst[i_dst] = inst->opc;
	i_dst += 1;
	if (inst->has_coding_byte)
	{
		dst[i_dst] = cw_op_get_full_coding_byte(inst->types);
		i_dst += 1;	
	}
	if (inst->args_count > 0)
		i_dst += cw_inst_write_arg(inst, 0, &dst[i_dst]);
	if (inst->args_count > 1)
		i_dst += cw_inst_write_arg(inst, 1, &dst[i_dst]);
	if (inst->args_count > 2)
		i_dst += cw_inst_write_arg(inst, 2, &dst[i_dst]);
	return (i_dst);
}
