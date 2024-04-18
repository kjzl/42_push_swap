/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:24:43 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:25 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/// @brief Rotates stack a by shifting up all elements by one.
/// @param a The stack to rotate.
/// @param b Unused.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	_ra(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->len < 2)
		return (FALSE);
	return (vec_rotate(a, 1));
}

/// @brief Rotates stack b by shifting up all elements by one.
/// @param a Unused.
/// @param b The stack to rotate.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	_rb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->len < 2)
		return (FALSE);
	return (vec_rotate(b, 1));
}

/// @brief Rotates stack a and b by shifting up all elements by one.
/// @param a The stack to rotate.
/// @param b The stack to rotate.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	_rr(t_stack *a, t_stack *b)
{
	t_bool	out;

	out = _ra(a, b);
	return (_rb(a, b) && out);
}
