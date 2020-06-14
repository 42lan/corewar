/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:14:53 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/14 20:16:40 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

int					cw_vm_op_lldi_dir(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int total;

	total = ft_bigendian16_read(vm->arena + ((game->procs->pos + pos) % CW_MEM_SIZE));
	return (total);
}

int16_t				cw_vm_op_lldi_ind(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int16_t			arg;
	int				total;
	int				idx_address;

	arg = ft_bigendian16_read(vm->arena + ((game->procs->pos + pos) % CW_MEM_SIZE));
	idx_address = (game->procs->pos + (arg % CW_IDX_MOD)) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	total = ft_bigendian32_read(vm->arena + idx_address);
	return (total);
}

int					cw_vm_op_lldi_value_reg(t_cw_vm *vm, int pos)
{
	int total;

	total = ft_bigendian32_read(vm->arena + pos);
	return (total);
}

void				cw_vm_op_lldi_body(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int				i;
	int				arg[3];
	int				pos;

	i = -1;
	pos = 2;
	while (++i < 2)
	{
		if (inst->types[i] == T_REG)
		{
			if (cw_vm_is_reg(vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE]) == false)
				return ;
			arg[i] = game->procs->regs[(vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE]) - 1];
			pos++;
		}
		else if (inst->types[i] == T_DIR)
		{
			arg[i] = cw_vm_op_lldi_dir(game, vm, pos);
			pos += CW_DIR_SIZE_LLDI;
		}
		else if (inst->types[i] == T_IND)
		{
			arg[i] = cw_vm_op_lldi_ind(game, vm, pos);
			pos += 2;
		}
	}
	arg[0] = (game->procs->pos + (arg[0] + arg[1])) % CW_MEM_SIZE;
	if (arg[0] < 0)
		arg[0] += CW_MEM_SIZE;
	arg[2] = vm->arena[(game->procs->pos + pos) % CW_MEM_SIZE];
	if (cw_vm_is_reg(arg[2]))
		game->procs->regs[arg[2] - 1] = cw_vm_op_lldi_value_reg(vm, arg[0]);
}

void	cw_vm_op_lldi(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count >= 3 && inst->types[1] != T_IND && inst->types[2] == T_REG)
		cw_vm_op_lldi_body(inst, game, vm);
	game->procs->pos = (game->procs->pos + 2 + cw_vm_add_pos(inst, 3, CW_DIR_SIZE_LLDI)) % CW_MEM_SIZE;
}
