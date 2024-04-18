/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:09:49 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:32:39 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/// @brief Swaps the top two elements of stack a.
/// @param a The stack to swap the top two elements of.
/// @param b Unused.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	sa(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->len < 2)
		return (FALSE);
	vec_swap_at(a, a->len - 1, a, a->len - 2);
	return (TRUE);
}

/// @brief Swaps the top two elements of stack b.
/// @param a Unused.
/// @param b The stack to swap the top two elements of.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	sb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->len < 2)
		return (FALSE);
	vec_swap_at(b, b->len - 1, b, b->len - 2);
	return (TRUE);
}

/// @brief Swaps the top two elements of stack a and b.
/// @param a The stack to swap the top two elements of.
/// @param b The stack to swap the top two elements of.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	ss(t_stack *a, t_stack *b)
{
	t_bool	out;

	out = sa(a, b);
	return (sb(a, b) && out);
}
