/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:13:22 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/12 16:20:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

int					cw_vm_op_sti_dir(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int 			total;
	int 			i;
	int 			pow;

	i = -1;
	total = 0;
	pow = ft_pow(256, CW_DIR_SIZE_STI - 1);
	while (++i < CW_DIR_SIZE_STI)
	{
		total += pow * vm->arena[(game->procs->pos + pos + i) % CW_MEM_SIZE];
		pow /= 256;
	}
	return (total);
}

int16_t				cw_vm_op_sti_ind(t_cw_game *game, t_cw_vm *vm, int pos)
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
	mult = ft_pow(256, CW_DIR_SIZE_STI - 1);
	while (++i < CW_DIR_SIZE_STI)
	{
		total += mult * vm->arena[(idx_address + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	return (arg);
}

void			cw_vm_op_sti_body(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int 		i;
	int 		idx_address;
	int			arg[3];
	int			pos;
	int 		reg_value;
	int 		pow;

	i = 0;
	pos = 3;
	reg_value = 0;
	while (++i < 3)
	{
		if (inst->args[i] == T_REG)
		{
			if (cw_vm_is_reg(vm->arena[game->procs->pos + pos]) == false)
				ft_printf("ERROR\n");
			arg[i] = game->procs->regs[(vm->arena[game->procs->pos + pos]) - 1];
			pos++;
		}
		else if (inst->args[i] == T_DIR)
		{
			arg[i] = cw_vm_op_sti_dir(game, vm, pos);
			pos += CW_DIR_SIZE_STI;
		}
		else if (inst->args[i] == T_IND)
		{
			arg[i] = cw_vm_op_sti_ind(game, vm, pos);
			pos += 2;
		}
	}
	idx_address = game->procs->pos + (arg[1] + arg[2]) % CW_IDX_MOD;
	pow = ft_pow(256, 3);
	i = -1;
	reg_value = game->procs->regs[game->procs->pos + 1];
	while (++i < 4)
	{
		vm->arena[(idx_address + i) % CW_MEM_SIZE] = reg_value / pow;
		reg_value %= pow;
		pow /= 256;
	}
	game->procs->pos = pos;
}

void			cw_vm_op_sti(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	if (inst->args_count != 3)
		ft_printf("ERROR\n");
	if (inst->types[0] != T_REG || inst->types[2] == T_IND)	
		ft_printf("ERROR\n");
	cw_vm_op_sti_body(inst, game, vm);
}
