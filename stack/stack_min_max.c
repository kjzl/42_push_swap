/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:15:25 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 18:04:54 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "../libft/libft.h"

/// UB if the stack is empty.
t_entry	stack_min(t_stack *s)
{
	t_node	*min;
	size_t	min_i;
	size_t	i;
	t_node	*node;

	node = s->head;
	min = node;
	min_i = 0;
	i = 1;
	while (i < s->len)
	{
		node = node->next;
		if (node->val < min->val)
		{
			min = node;
			min_i = i;
		}
		i++;
	}
	return ((t_entry){min_i, min});
}

/// UB if the stack is empty.
t_entry	stack_max(t_stack *s)
{
	t_node	*max;
	size_t	max_i;
	size_t	i;
	t_node	*node;

	node = s->head;
	max = node;
	max_i = 0;
	i = 1;
	while (i < s->len)
	{
		node = node->next;
		if (node->val > max->val)
		{
			max = node;
			max_i = i;
		}
		i++;
	}
	return ((t_entry){max_i, max});
}

void	stack_min2(t_stack *s, t_entry *min1, t_entry *min2)
{
	size_t	i;
	t_node	*node;

	node = s->head->next;
	*min1 = (t_entry){0, s->head};
	*min2 = (t_entry){1, s->head->next};
	if (s->head->val >= s->head->next->val)
		ft_memswap(min1, min2, sizeof(t_entry));
	i = 2;
	while (i < s->len)
	{
		node = node->next;
		if (node->val < min1->node->val)
		{
			*min2 = *min1;
			*min1 = (t_entry){i, node};
		}
		else if (node->val < min2->node->val)
			*min2 = (t_entry){i, node};
		i++;
	}
}

void	stack_max2(t_stack *s, t_entry *max1, t_entry *max2)
{
	size_t	i;
	t_node	*node;

	node = s->head->next;
	*max1 = (t_entry){0, s->head};
	*max2 = (t_entry){1, s->head->next};
	if (s->head->val <= s->head->next->val)
		ft_memswap(max1, max2, sizeof(t_entry));
	i = 2;
	while (i < s->len)
	{
		node = node->next;
		if (node->val > max1->node->val)
		{
			*max2 = *max1;
			*max1 = (t_entry){i, node};
		}
		else if (node->val > max2->node->val)
			*max2 = (t_entry){i, node};
		i++;
	}
}
