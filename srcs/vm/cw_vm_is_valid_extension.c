/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_is_valid_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 04:59:19 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 05:13:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_errors.h"

/*
** cw_vm_is_valid_extension() checks whether `av` ends in `extension`
*/

int		cw_vm_is_valid_extension(const char *av, const char *extension)
{
	if (av == NULL || !*av || extension == NULL || !*extension)
		return (CW_FAILURE);
	if ((extension = ft_strrchr(av, '.')) != NULL)
		if (ft_strequ(extension, ".cor"))
			return (CW_SUCCESS);
	return (CW_FAILURE);
}
