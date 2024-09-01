/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:36:35 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:36:36 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*node_at(const t_stack *stack, size_t index)
{
	size_t	i;
	t_node	*node;

	if (index >= stack->len)
		return (0);
	i = 0;
	node = stack->head;
	while (index - i >= STACK_FAST_STEP)
	{
		node = stack->head->fast_next;
		i += STACK_FAST_STEP;
	}
	while (i < index)
	{
		node = node->next;
		i++;
	}
	return (node);
}

t_node	*node_at_slow(const t_stack *stack, size_t index)
{
	size_t	i;
	t_node	*node;

	if (index >= stack->len)
		return (0);
	i = 0;
	node = stack->head;
	while (i < index)
	{
		node = node->next;
		i++;
	}
	return (node);
}

t_node	*node_by_val(const t_stack *stack, int32_t val)
{
	t_node	*node;

	if (stack->len == 0)
		return (0);
	node = stack->head;
	while (TRUE)
	{
		if (node->val == val)
			return (node);
		node = node->next;
		if (node == stack->head)
			break ;
	}
	return (0);
}
