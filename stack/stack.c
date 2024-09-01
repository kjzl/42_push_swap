/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:59 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:42:46 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_entry	entry_at(t_stack *s, size_t i)
{
	return ((t_entry){i, node_at(s, i)});
}

t_bool	stack_is_sorted(t_stack *s, t_bool at_head, size_t n)
{
	t_node	*node;
	size_t	i;

	if (s->len < 2)
		return (TRUE);
	if (at_head)
		node = s->head;
	else if (s->id == stack_a)
		node = stack_min(s).node;
	else
		node = stack_max(s).node;
	i = 0;
	while (i < s->len - 1 && i < n)
	{
		if (s->id == stack_a && node->val > node->next->val)
			return (FALSE);
		if (s->id == stack_b && node->val < node->next->val)
			return (FALSE);
		node = node->next;
		i++;
	}
	return (TRUE);
}

/// @brief Returns the distance of the node from the top of the stack.
size_t	node_dist(t_entry n)
{
	return (n.index);
}

/// @brief Returns the distance of the node from the top of the stack
/// when traversing the stack in reverse order.
size_t	node_rdist(t_stack *s, t_entry n)
{
	if (n.index == 0)
		return (0);
	return (s->len - n.index);
}
