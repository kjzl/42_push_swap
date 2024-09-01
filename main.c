/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:15:48 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:41:21 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/// Checks if the Stack contains duplicates and returns
/// the index of the first duplicate.
int32_t	stack_checkdup(t_stack *s)
{
	t_node	*current;
	t_node	*runner;
	size_t	index;
	size_t	runner_index;

	current = s->head;
	index = 0;
	while (index < s->len)
	{
		runner = current->next;
		runner_index = index + 1;
		while (runner != s->head)
		{
			if (current->val == runner->val)
				return (runner_index);
			runner = runner->next;
			runner_index++;
		}
		current = current->next;
		index++;
	}
	return (-1);
}

int32_t	main(int32_t argc, const char **argv)
{
	t_ps	ps;

	ps.b = stack_new(stack_b);
	if (argc == 2)
		ps.a = parse_stack_str(cstr_view(argv[1]));
	else if (argc > 2)
		ps.a = parse_stack(argv + 1, argc - 1);
	else
		return (0);
	if (ps.a.len < 2)
		return (1);
	if (stack_checkdup(&ps.a) != -1)
	{
		ft_printf_fd(STDERR, "Error\nDuplicate value at index %d.\n",
			stack_checkdup(&ps.a));
		return (1);
	}
	sort(&ps);
	return (0);
}
