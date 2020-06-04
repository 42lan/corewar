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

int		cw_vm_get_player(char *str, int number)
{
	int i;

	i = -1;
	ft_printf("{pink}str = %s\n{}", str);
	(void)number;
	if (str == NULL)
		return (CW_ERROR);
	while (str[++i] && ft_strchr(str + (i + 1), '.') != NULL)
		if (ft_isalnum(str[i]) == 0)
			return (CW_ERROR);
	if (i == 0 && str[i] != '.')
		return (CW_ERROR);
	if (ft_strequ(str + i, ".cor\0") == 0)
		return (CW_ERROR);
	ft_printf("SUCCESS\n");
	return (CW_SUCCESS);
}

int		cw_vm_parsing(int argc, char **argv, t_cw_data *data)
{
	int			i;
	int			value;
	char		*tmp;

	i = -1;
	while (++i < argc)
	{
		tmp = ft_strtrim(argv[i]);
		//if (ft_strequ(argv[i] + ft_strspn(argv[i], " \t"), "-dump") == 1)
		if (ft_strequ(tmp, "-dump") == 1)
		{
			i++;
			if (ft_atoi32check(&value, argv[i] + ft_strspn(argv[i], " \t")) != 0 || value < 0)
			{
				free(tmp);
				return (CW_VM_NO_VALID_ARGUMENT_DUMP);
			}
			data->nbr_cycles = value;
			ft_printf("{green}-dump is okay %d\n{}", value);
		}
		if (ft_strequ(tmp, "-n") == 1)
		{
			i++;
			if (ft_atoi32check(&value, argv[i] + ft_strspn(argv[i], " \t")) != 0 || value <= 0)
			{
				free(tmp);
				return (CW_VM_NO_VALID_ARGUMENT_DUMP);
			}
			data->number = value;
			cw_vm_get_player(argv[i + 1], value);
		}
		free(tmp);
	}
	return (CW_SUCCESS);
}
