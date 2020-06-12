/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:15:08 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/12 16:13:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

int		cw_vm_op_and_dir(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int total;
	int i;
	int pow;

	i = -1;
	total = 0;
	pow = ft_pow(256, CW_DIR_SIZE_AND - 1);
	while (++i < CW_DIR_SIZE_AND)
	{
		total += pow * vm->arena[(game->procs->pos + pos + i) % CW_MEM_SIZE];
		pow /= 256;
	}
	return (total);
}

int16_t	cw_vm_op_and_ind(t_cw_game *game, t_cw_vm *vm, int pos)
{
	int				i;
	int16_t			arg;
	int				total;
	unsigned int	mult;
	int				idx_address;

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
	mult = ft_pow(256, CW_DIR_SIZE_AND - 1);
	while (++i < CW_DIR_SIZE_AND)
	{
		total += mult * vm->arena[(idx_address + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	return (arg);
}

void	cw_vm_op_and_body(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int i;
	int	arg[3];
	int	pos;
	int reg_value;

	i = -1;
	pos = 2;
	reg_value = 0;
	while (++i < 2)
	{
		ft_printf("{yellow}pos = %d\n inst->types[%d] = %d\n{}", pos, i, inst->types[i]);
		if (inst->types[i] == T_REG)
		{
			ft_printf("{green}enter in t_REG\n{}");
			if (cw_vm_is_reg(vm->arena[game->procs->pos + pos]) == false)
				ft_printf("ERROR\n");
			arg[i] = game->procs->regs[(vm->arena[game->procs->pos + pos]) - 1];
			pos++;
		}
		else if (inst->types[i] == T_DIR)
		{
			ft_printf("{green}enter in t_DIR\n{}");
			arg[i] = cw_vm_op_and_dir(game, vm, pos);
			pos += CW_DIR_SIZE_AND;
		}
		else if (inst->types[i] == T_IND)
		{
			ft_printf("{green}enter in t_IND\n{}");
			arg[i] = cw_vm_op_and_ind(game, vm, pos);
			pos += 2;
		}
	}
	ft_printf("{yellow}pos = %d\n{}", pos);
	reg_value = arg[0] & arg[1];
	game->procs->regs[game->procs->pos + pos - 1] = reg_value;
	game->procs->carry = (reg_value == 0) ? 1 : 0;
	game->procs->pos += (pos + 1);
	ft_printf("{pink}|||||||||||||||||||||||case = %d\n", vm->arena[game->procs->pos]);
}

void	cw_vm_op_and(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	ft_printf("debut de and\n");
	if (inst->args_count != 3)
		ft_printf("ERROR\n");
	if (inst->types[2] != T_REG)	
		ft_printf("ERROR\n");
	cw_vm_op_and_body(inst, game, vm);
	ft_printf("fin de and\n");
}
