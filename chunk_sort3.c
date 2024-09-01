/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:33:39 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:58:07 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3_a_start(t_ps *ps, uint32_t max)
{
	if (ps->a.head->target_pos > ps->a.head->next->target_pos)
		sa(&ps->a);
	if (ps->a.head->next->target_pos == max)
		ra(&ps->a);
	if (ps->a.head->target_pos > ps->a.head->next->target_pos)
		sa(&ps->a);
	if (ps->a.head->next->target_pos == max)
		rra(&ps->a);
	if (ps->a.head->target_pos > ps->a.head->next->target_pos)
		sa(&ps->a);
}

static	void	sort3_a_end(t_ps *ps, uint32_t max)
{
	rrx_n(&ps->a, 2);
	if (ps->a.head->target_pos > ps->a.head->next->target_pos)
		sa(&ps->a);
	if (ps->a.head->target_pos == max - 2)
		pb(&ps->a, &ps->b);
	rra(&ps->a);
	if (ps->a.head->target_pos > ps->a.head->next->target_pos)
		sa(&ps->a);
	if (ps->a.head->target_pos != max - 2)
		pa(&ps->a, &ps->b);
}

static void	sort3_b_start(t_ps *ps, uint32_t max)
{
	if (ps->b.head->next->target_pos == max)
		sb(&ps->b);
	if (ps->b.head->target_pos == max)
		px_n(&ps->b, &ps->a, 3);
	else
	{
		pa(&ps->a, &ps->b);
		sb(&ps->b);
		pa(&ps->a, &ps->b);
		sa(&ps->a);
		pa(&ps->a, &ps->b);
	}
	if (ps->a.head->target_pos == max - 1)
		sa(&ps->a);
}

static void	sort3_b_end(t_ps *ps, t_chunk *chunk, uint32_t max)
{
	if (chunk->first->target_pos == max)
	{
		rrx_n(&ps->b, 3);
		px_n(&ps->b, &ps->a, 3);
	}
	else if (chunk->first->next->target_pos == max)
	{
		rrx_n(&ps->b, 2);
		pa(&ps->a, &ps->b);
		if (ps->b.head->target_pos == max - 1)
			pa(&ps->a, &ps->b);
		rrb(&ps->b);
		pa(&ps->a, &ps->b);
		if (ps->a.head->target_pos == max - 1)
			pa(&ps->a, &ps->b);
	}
	else
	{
		rrb(&ps->b);
		pa(&ps->a, &ps->b);
		rrb(&ps->b);
		pa(&ps->a, &ps->b);
		rrb(&ps->b);
		pa(&ps->a, &ps->b);
	}
}

/// Sorts this chunk's 3 elements to the top of stack A
/// Only useable if this chunk has exactly 3 elements
void	chunk_sort3(t_ps *ps, t_chunk *chunk)
{
	uint32_t	max;

	max = chunk_max(*chunk);
	if (chunk->first == ps->a.head)
	{
		if (chunk->len == chunk->stack->len)
			return (stack_sort3(chunk->stack));
		sort3_a_start(ps, max);
	}
	else if (chunk->stack->id == stack_a)
		sort3_a_end(ps, max);
	else if (chunk->first == ps->b.head)
		sort3_b_start(ps, max);
	else
	{
		sort3_b_end(ps, chunk, max);
		if (ps->a.head->target_pos == max - 1)
			sa(&ps->a);
	}
}
