/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:32:09 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/13 20:29:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm_game.h"
#include "cw_inst.h"

void		cw_vm_op_st_ind_exec(t_cw_game *game, t_cw_vm *vm)
{
	int		i;
	int		mult;
	int 	reg_value;
	int 	reg_index;
	int16_t arg2;

	i = -1;
	arg2 = 0;
	mult = 256;
	reg_index = vm->arena[(game->procs->pos + 2) % CW_MEM_SIZE];
	if (reg_index < 1 || reg_index > 16)
		ft_printf("ERROR\n");
	reg_value = game->procs->regs[reg_index - 1];
	while (++i < 2)
	{
		arg2 += mult * vm->arena[(game->procs->pos + 3 + i) % CW_MEM_SIZE];
		mult /= 256;
	}
	arg2 = game->procs->pos + (arg2 % CW_IDX_MOD);
	if (arg2 < 0)
		arg2 += CW_MEM_SIZE;
	ft_bigendian32_write(vm->arena + (arg2) % CW_MEM_SIZE, reg_value);
}


void	cw_vm_op_st(t_cw_inst *inst, t_cw_game *game, t_cw_vm *vm)
{
	int		arg[2];

	if (inst->args_count == 2 && inst->types[0] == T_REG && inst->types[1] != T_DIR)
	{
		if (inst->types[1] == T_REG)
		{
			arg[0] = vm->arena[(game->procs->pos + 2) % CW_MEM_SIZE];
			arg[1] = vm->arena[(game->procs->pos + 3) % CW_MEM_SIZE];
			if (cw_vm_is_reg(arg[0]) == true && cw_vm_is_reg(arg[1]) == true)
				game->procs->regs[arg[1] - 1] = game->procs->regs[arg[0] - 1];
		}
		else if (inst->types[1] == T_IND)
			cw_vm_op_st_ind_exec(game, vm);
	}
	// opc + encoding byte + T_REG + (T_REG | T_IND)
	// 4 T_REG, 5 T_IND
	game->procs->pos += (1 + 1 + 1 + ((inst->types[0] == T_REG) ? 1 : 2)) % CW_MEM_SIZE;
}
