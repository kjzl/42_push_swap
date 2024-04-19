/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_serialize_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:55:08 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 04:31:35 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	iter_max(t_stack *stack, size_t i, int *max)
{
	int	at_i;

	at_i = *stack_get_at(stack, i);
	if (at_i > *max)
		*max = at_i;
}

static void	iter_min(t_stack *stack, size_t i, int *min)
{
	int	at_i;

	at_i = *stack_get_at(stack, i);
	if (at_i < *min)
		*min = at_i;
}

/// @brief Returns the maximum value in the stack.
/// @param stack The stack.
/// @return The maximum value.
/// @note If the stack is empty, the return value is 0.
int	stack_max(const t_stack *stack)
{
	int	max;

	max = 0;
	vec_iteri(stack, iter_max, &max);
	return (max);
}

/// @brief Returns the minimum value in the stack.
/// @param stack The stack.
/// @return The minimum value.
/// @note If the stack is empty, the return value is 0.
int	stack_min(const t_stack *stack)
{
	int	min;

	min = 0;
	vec_iteri(stack, iter_min, &min);
	return (min);
}

int	int_width(int i)
{
	t_str	to_str;

	to_str = str_itoa(i, str_base10());
	if (to_str.heap)
		free(to_str._capacity);
	return (to_str.len);
}
