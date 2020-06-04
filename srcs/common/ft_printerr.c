/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 01:32:09 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/05 01:35:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw_errors.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_printerr(const char *where, const char *what)
{
	ft_dprintf(STDERR_FILENO, "{red}ERROR: ");
	ft_dprintf(STDERR_FILENO, "%s - %s\n", where, what);
	ft_dprintf(STDERR_FILENO, "{}");
	exit(CW_ERROR);

}
