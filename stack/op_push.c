/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:16:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:28:16 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/// @brief Pushes the top element of stack b to stack a.
/// @param a The stack to push to.
/// @param b The stack to push from.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	pa(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return (FALSE);
	vec_push(a, vec_get_last(b));
	vec_remove_last(b);
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
	vec_push(b, vec_get_last(a));
	vec_remove_last(a);
	return (TRUE);
}
