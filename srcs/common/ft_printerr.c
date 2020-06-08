/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 01:32:09 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/05 15:12:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_errors.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_printerr(const char *error)
{
	ft_dprintf(STDERR_FILENO, "{red}ERROR");
	if (error)
		ft_dprintf(STDERR_FILENO, ": %s", error);
	ft_dprintf(STDERR_FILENO, "{}\n");
	exit(CW_ERROR);

}
