/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:06:54 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/04 14:06:54 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_vm.h"
#include "cw_vm_parsing.h"

int		cw_vm_parsing(int argc, char **argv)
{
	int		i;
	int		value;
	char	**split;

	i = -1;
	while (++i < argv)
	{
		if (ft_strequ(argv[i] + ft_strspn(argv[i], " \t"), "-dump") == 1)
		{
			i++;
			if (ft_atoi32check(&value, argv[i] + ft_strspn(argv[i], " \t")) != 0 || value < 0)
				return (CW_VM_NO_VALID_ARGUMENT_DUMP);

		}
	}
}
