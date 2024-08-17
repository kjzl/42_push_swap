/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:33:43 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 04:14:26 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# pragma once

# include "stack/stack.h"

typedef enum e_exit_status
{
	status_ok,
	status_err,
	status_err_malloc,
	status_err_args,
	status_err_parse_arg,
}		t_exit_status;

void	exit_status(t_exit_status status);

#endif
