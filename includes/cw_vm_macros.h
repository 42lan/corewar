/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:58:11 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 22:58:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_VM_MACROS_H
# define CW_VM_MACROS_H

# define CW_MAX_PLAYERS			4
# define CW_NOT_LAST_PROC		0
# define CW_LAST_PROC			1
# define CW_CYCLE_TO_DIE		1536
# define CW_CYCLE_DELTA			50
# define CW_REG_NUMBER			16
# define CW_NBR_LIVE			21
# define CW_MAX_CHECKS			10
# define CW_VM_DUMP				471

# define CW_DIR_SIZE_LIVE		4
# define CW_DIR_SIZE_LD			4
# define CW_DIR_SIZE_ST			4
# define CW_DIR_SIZE_ADD		4
# define CW_DIR_SIZE_SUB		4
# define CW_DIR_SIZE_AND		4
# define CW_DIR_SIZE_OR			4
# define CW_DIR_SIZE_XOR		4
# define CW_DIR_SIZE_ZJMP		2
# define CW_DIR_SIZE_LDI		2
# define CW_DIR_SIZE_STI		2
# define CW_DIR_SIZE_FORK		2
# define CW_DIR_SIZE_LLD		4
# define CW_DIR_SIZE_LLDI		2
# define CW_DIR_SIZE_LFORK		2
# define CW_DIR_SIZE_AFF		4

#endif
