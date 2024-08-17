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

/// @brief Pushes the top element of stack b to stack a.
/// @param a The stack to push to.
/// @param b The stack to push from.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	pa(t_stack *a, t_stack *b)
{
	if (b->s.len == 0)
		return (FALSE);
	vec_push(&a->s, vec_get_last(&b->s));
	vec_remove_last(&b->s);
	return (TRUE);
}

/// @brief Pushes the top element of stack a to stack b.
/// @param a The stack to push from.
/// @param b The stack to push to.
/// @return TRUE if the operation was successful, FALSE otherwise.
t_bool	pb(t_stack *a, t_stack *b)
{
	if (a->s.len == 0)
		return (FALSE);
	vec_push(&b->s, vec_get_last(&a->s));
	vec_remove_last(&a->s);
	return (TRUE);
}
