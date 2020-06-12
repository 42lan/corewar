/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_xor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:11:41 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/12 20:27:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

int					cw_vm_op_xor_dir(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int 			i;
	int 			pow;
	int 			total;

	i = -1;
	total = 0;
	pow = ft_pow(256, CW_DIR_SIZE_XOR - 1);
	while (++i < CW_DIR_SIZE_XOR)
	{
		total += pow * vm->arena[(game->procs->pos + pos + i) % CW_MEM_SIZE];
		pow /= 256;
	}
	return (total);
}

int16_t				cw_vm_op_xor_ind(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int				i;
	int				total;
	int				idx_address;
	int16_t			arg;
	unsigned int	mult;

	i = -1;
	arg = 0;
	total = 0;
	mult = 256;
	while (++i < 2)
	{
		arg += mult * vm->arena[(game->procs->pos + pos + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	idx_address = (game->procs->pos + (arg % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	i = -1;
	arg = 0;
	mult = ft_pow(256, CW_DIR_SIZE_XOR - 1);
	while (++i < CW_DIR_SIZE_XOR)
	{
		total += mult * vm->arena[(idx_address + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	return (arg);
}

void				cw_vm_op_xor_body(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int 			i;
	int				pos;
	int 			reg_value;
	int				arg[3];

	i = -1;
	pos = 1;
	reg_value = 0;
	while (++i < 2)
		if (inst->types[i] == T_REG)
		{
			if (cw_vm_is_reg(vm->arena[game->procs->pos + pos + i]) == false)
				ft_printf("ERROR\n");
			arg[i] = game->procs->regs[(vm->arena[game->procs->pos + pos + i]) - 1];
			pos++;
		}
		else if (inst->types[i] == T_DIR)
		{
			arg[i] = cw_vm_op_xor_dir(game, vm, pos + 1);
			pos += CW_DIR_SIZE_XOR;
		}
		else if (inst->types[i] == T_IND)
		{
			arg[i] = cw_vm_op_xor_ind(game, vm, pos);
			pos += 2;
		}
	reg_value = arg[0] ^ arg[1];
	game->procs->regs[game->procs->pos + pos - 1] = reg_value;
	game->procs->carry = (reg_value == 0) ? 1 : 0;
	game->procs->pos = pos + 1;
}

void				cw_vm_op_xor(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count != 3 || inst->types[2] != T_REG)	
		ft_printf("ERROR\n");
	cw_vm_op_xor_body(inst, game, vm);
}
