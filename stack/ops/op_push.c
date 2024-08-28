/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:16:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:13 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "ft_types.h"

/// @brief Pushes the top element of stack b to stack a.
/// @param a The stack to push to.
/// @param b The stack to push from.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	pa(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return (FALSE);
	stack_push(a, stack_pop(b));
	print_sort_op(op_pa);
	return (TRUE);
}

/// @brief Pushes the top element of stack a to stack b.
/// @param a The stack to push from.
/// @param b The stack to push to.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	pb(t_stack *a, t_stack *b)
{
	if (a->len == 0)
		return (FALSE);
	stack_push(b, stack_pop(a));
	print_sort_op(op_pb);
	return (TRUE);
}

t_bool	px(t_stack *from, t_stack *to)
{
	if (from == to)
		return (FALSE);
	if (to->id == stack_a)
		return (pa(to, from));
	else
		return (pb(from, to));
}

void	px_n(t_stack *from, t_stack *to, size_t n)
{
	while (n--)
		px(from, to);
}
