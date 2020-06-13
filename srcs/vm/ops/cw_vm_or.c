/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:19:21 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/13 21:10:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

int					cw_vm_op_or_dir(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int 			i;
	int 			pow;
	int 			total;

	i = -1;
	total = 0;
	pow = ft_pow(256, CW_DIR_SIZE_OR - 1);
	while (++i < CW_DIR_SIZE_OR)
	{
		total += pow * vm->arena[(game->procs->pos + pos + i) % CW_MEM_SIZE];
		pow /= 256;
	}
	return (total);
}

int16_t	cw_vm_op_or_ind(t_cw_game *game, t_cw_vm *vm, int pos)
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
	mult = ft_pow(256, CW_DIR_SIZE_OR - 1);
	while (++i < CW_DIR_SIZE_OR)
	{
		total += mult * vm->arena[(idx_address + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	return (arg);
}

void				cw_vm_op_or_body(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int 			i;
	int				pos;
	int 			reg_value;
	int				arg[3];

	i = -1;
	pos = 2;
	reg_value = 0;
	while (++i < 2)
		if (inst->types[i] == T_REG)
		{
			if (cw_vm_is_reg(vm->arena[game->procs->pos + pos]) == false)
				ft_printf("ERROR\n");
			arg[i] = game->procs->regs[(vm->arena[game->procs->pos + pos]) - 1];
			pos++;
		}
		else if (inst->types[i] == T_DIR)
		{
			arg[i] = cw_vm_op_or_dir(game, vm, pos);
			pos += CW_DIR_SIZE_OR;
		}
		else if (inst->types[i] == T_IND)
		{
			arg[i] = cw_vm_op_or_ind(game, vm, pos);
			pos += 2;
		}
	reg_value = arg[0] | arg[1];
	game->procs->regs[vm->arena[game->procs->pos + pos] - 1] = reg_value;
	game->procs->carry = (reg_value == 0) ? 1 : 0;
}

void	cw_vm_op_or(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count == 3 && inst->types[2] == T_REG)
		cw_vm_op_or_body(inst, game, vm);
	// opc + encoding byte + (T_REG | T_DIR | T_IND) + (T_REG | T_DIR | T_IND) + T_REG
	//  5 T_REG T_REG
	//  8 T_REG T_DIR
	//  6 T_REG T_IND
	//  8 T_DIR T_REG
	// 11 T_DIR T_DIR
	//  9 T_DIR T_IND
	//  6 T_IND T_REG
	//  9 T_IND T_DIR
	//  7 T_IND T_IND
	game->procs->pos += (1 + 1) % CW_MEM_SIZE;
	if (inst->types[0] == T_REG)
		game->procs->pos += (1) % CW_MEM_SIZE;
	else if (inst->types[0] == T_DIR)
		game->procs->pos += (CW_DIR_SIZE_OR) % CW_MEM_SIZE;
	else if (inst->types[0] == T_IND)
		game->procs->pos += (2) % CW_MEM_SIZE;
	if (inst->types[1] == T_REG)
		game->procs->pos += (1) % CW_MEM_SIZE;
	else if (inst->types[1] == T_DIR)
		game->procs->pos += (CW_DIR_SIZE_OR) % CW_MEM_SIZE;
	else if (inst->types[1] == T_IND)
		game->procs->pos += (2) % CW_MEM_SIZE;
	game->procs->pos += (1) % CW_MEM_SIZE;
	/* ft_printf("0x%02x 0x%02x 0x%02x\n", vm->arena[game->procs->pos-1], vm->arena[game->procs->pos], vm->arena[game->procs->pos + 1]); */
}
