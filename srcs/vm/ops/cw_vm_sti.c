/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:13:22 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/14 18:37:54 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

int					cw_vm_op_sti_dir(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int total;

	total = ft_bigendian16_read(vm->arena + ((game->procs->pos + pos) % CW_MEM_SIZE));
	return (total);
}

int					cw_vm_op_sti_ind(t_cw_game *game, t_cw_vm *vm, int pos)
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

void			cw_vm_op_sti_body(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int 		i;
	int 		idx_address;
	int			arg[3];
	int			pos;
	int 		reg_value;

	i = 0;
	pos = 3;
	reg_value = 0;
	while (++i < 3)
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
			arg[i] = cw_vm_op_sti_dir(game, vm, pos);
			pos += CW_DIR_SIZE_STI;
		}
		else if (inst->types[i] == T_IND)
		{
			arg[i] = cw_vm_op_sti_ind(game, vm, pos);
			pos += 2;
		}
	}
	idx_address = (game->procs->pos + (arg[1] + arg[2]) % CW_IDX_MOD) % CW_MEM_SIZE;
	if (idx_address < 0)
		idx_address += CW_MEM_SIZE;
	arg[0] = vm->arena[game->procs->pos +  2];
	if (cw_vm_is_reg(arg[0]))
	{
		reg_value = game->procs->regs[arg[0] - 1];
		ft_bigendian32_write(vm->arena + idx_address, reg_value);
	}
}

void			cw_vm_op_sti(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count >= 3 && inst->types[0] == T_REG && inst->types[2] != T_IND)
		cw_vm_op_sti_body(inst, game, vm);
	game->procs->pos = (game->procs->pos + 2 + cw_vm_add_pos(inst, 3, CW_DIR_SIZE_STI)) % CW_MEM_SIZE;
}
