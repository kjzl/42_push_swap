/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:30:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:37 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/// @brief Rotates stack a in reverse by shifting down all elements by one.
/// @param a The stack to rotate.
/// @param b Unused.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	_rra(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->len < 2)
		return (FALSE);
	return (vec_rrotate(a, 1));
}

/// @brief Rotates stack b in reverse by shifting down all elements by one.
/// @param a Unused.
/// @param b The stack to rotate.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	_rrb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->len < 2)
		return (FALSE);
	return (vec_rrotate(b, 1));
}

/// @brief Rotates stack a and b in reverse by shifting down all elements by one
/// @param a The stack to rotate.
/// @param b The stack to rotate.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	_rrr(t_stack *a, t_stack *b)
{
	t_bool	out;

	out = _rra(a, b);
	return (_rrb(a, b) && out);
}
