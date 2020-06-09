/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_op_ld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 01:22:20 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/09 16:24:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_operations.h"

void	cw_vm_op_ld_dir_exec(t_cw_battle *battle, t_cw_vm *vm)
{
	int				i;
	int				index;
	unsigned int	arg1;
	unsigned int	multiplier;

	i = -1;
	arg1 = 0;
	multiplier = 256 * 256 * 256;
	while (++i < CW_DIR_SIZE_LD)
	{
		arg1 += multiplier * vm->arena[battle->processus->position + 2 + i];
		multiplier /= 256;
	}
	ft_printf("{red}ARG1    %ld\n", arg1);

	// Write the number from the first argument into the registry received as second argument
	index = vm->arena[battle->processus->position + 2 + i];
	battle->processus->registries[index] = arg1;
	ft_printf("reg[%d]  %ld\n", index, battle->processus->registries[index]);

	// If the written value is 0, then set carry to 1; if the written vaue is !0 then set carry to 0
	battle->processus->carry = (arg1 == 0) ? 0 : 1;
	ft_printf("carry   %d\n{}", battle->processus->carry);
	exit(1);
}

void	cw_vm_op_ld_ind_exec(t_cw_battle *battle, t_cw_vm *vm)
{
	int				i;
	int				index;
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	multiplier;
	int				idx_address;

	ft_printf("IDIRD\n");
	i = -1;
	arg1 = 0;
	multiplier = 256 * 256 * 256;
	while (++i < CW_DIR_SIZE_LD)
	{
		arg1 += multiplier * vm->arena[battle->processus->position + 2 + i];
		multiplier /= 256;
	}
	ft_printf("{red}ARG1    %ld\n", arg1);
	// Calculate address: current position of the cursor + <FIRST_ARGUMENT> % IDX_MOD.
	idx_address = vm->arena[battle->processus->position] + (arg1 % CW_IDX_MOD);
	// Read four bytes starting from the obtained address.
	// Write the value from the step 2 into the registry passed as the second argument.
	index = vm->arena[battle->processus->position + 2 + i];
	battle->processus->registries[index] = ;
	// If the written value is 0, then set carry to 1; if the written vaue is !0 then set carry to 0.
	battle->processus->carry = (battle->processus->registries[index] == 0) ? 1 : 0;

}

void	cw_vm_op_ld(t_cw_inst *inst, t_cw_battle *battle, t_cw_vm *vm)
{
	if (inst->args_count != 2)
		ft_printf("ERROR\n");
	if (inst->types[0] == T_REG || inst->types[1] != T_REG)	
		ft_printf("ERROR\n");
	if (inst->types[0] == T_DIR)
		cw_vm_op_ld_dir_exec(battle, vm);
	else if (inst->types[0] == T_IND)
		cw_vm_op_ld_ind_exec(battle, vm);
}
