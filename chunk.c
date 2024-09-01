/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:33:35 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:33:37 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	chunk_empty(t_chunk_ty type)
{
	t_chunk	chunk;

	chunk.first = 0;
	chunk.len = 0;
	chunk.stack = 0;
	chunk.type = type;
	return (chunk);
}

t_node	*chunk_top_node(t_chunk *chunk)
{
	if (chunk->len == 0)
		return (0);
	if (chunk->first == chunk->stack->head)
		return (chunk->first);
	else
		return (chunk->stack->head->prev);
}

uint32_t	chunk_max(t_chunk chunk)
{
	uint32_t	max;
	uint32_t	i;
	t_node		*node;

	max = 0;
	i = 0;
	node = chunk.first;
	while (i < chunk.len)
	{
		if (node->target_pos > max)
			max = node->target_pos;
		node = node->next;
		i++;
	}
	return (max);
}

uint32_t	chunk_min(t_chunk chunk)
{
	uint32_t	min;
	uint32_t	i;
	t_node		*node;

	min = UINT32_MAX;
	i = 0;
	node = chunk.first;
	while (i < chunk.len)
	{
		if (node->target_pos < min)
			min = node->target_pos;
		node = node->next;
		i++;
	}
	return (min);
}
