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

#include "ft_types.h"
#include "libft.h"
#include "push_swap.h"
#include "stack/stack.h"

// void	stack_print(t_stack *s)
// {
// 	size_t	i;
// 	t_node	*node;
// 	const char *stack_name;

// 	i = 0;
// 	node = s->head;
// 	if (s->id == stack_a)
// 		stack_name = "A";
// 	else
// 		stack_name = "B";

// 	// ft_printf_fd(STDERR, "%s: len = %d\n", stack_name, (int32_t)s->len);
// 	while (i < s->len)
// 	{
// 		// ft_printf_fd(STDERR, "%d\n", node->val);
// 		node = node->next;
// 		i++;
// 	}
// }

t_bool	stacks_finished(t_stack *a, t_stack *b)
{
	int32_t	prev_val;
	t_node	*node;

	(void)b;
	//if (b->len != 0)
	//	ft_printf_fd(STDERR, "STACK B NOT EMPTY!!");
	prev_val = a->head->val;
	node = a->head->next;
	while (node != a->head)
	{
		if (node->val < prev_val)
			return (FALSE);
		prev_val = node->val;
		node = node->next;
	}
	return (TRUE);
}

/// Checks if the Stack contains duplicates and returns the index of the first duplicate.
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
		ft_printf_fd(STDERR, "Error\nDuplicate value at index %d.\n", stack_checkdup(&ps.a));
		return (1);
	}
	//ft_printf_fd(STDERR, "INPUT:\n");
	// stack_print(&ps.a);
	sort(&ps);
	// ft_printf_fd(STDERR, "NOT SORTED!!\nNOT SORTED!!\n");
	if (!stacks_finished(&ps.a, &ps.b))
	{
		// stack_print(&ps.a);
		// stack_print(&ps.b);
		return (1);
	}
	return (0);
}
