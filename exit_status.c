/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:37:26 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 04:14:30 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*exit_status_msg(t_exit_status status)
{
	static char *msgs[] = {
		0,
		0,
		"Malloc error",
		"Usage: ./push_swap \"1 2 3 4 5\"",
		"Invalid input",
	};
	return (msgs[status]);
}

void	exit_status(t_exit_status status)
{
	const char	*msg;

	if (status == status_ok)
		exit(0);
	msg = exit_status_msg(status);
	ft_putstr_fd("Error\n", 2);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(status);
}
