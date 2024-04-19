/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:15:48 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 06:23:45 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_vec	stack_a;
	t_vec	stack_b;
	t_str	stacks_display;

	if (argc == 2)
	{
		stack_a = parse_stack(argv[1]);
		if (stack_a.mem_err)
			exit_status(status_err_malloc);
		if (stack_a.len == 0)
			exit_status(status_err_parse_arg);
		stack_b = vec_empty_with_capacity(sizeof(int), stack_a.len);
		if (stack_a.mem_err)
			exit_status(status_err_malloc);
		stacks_display = display_stacks(&stack_a, &stack_b);
		ft_putstr_fd(str_get(&stacks_display), 1);
		str_destroy(&stacks_display);
		// TODO
		// sort(&stack_a, &stack_b);
	}
	else
		exit_status(status_err_args);
	return (status_ok);
}
