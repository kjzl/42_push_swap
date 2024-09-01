/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:31:06 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 18:05:30 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sort3_a_start(t_ps *ps, uint32_t max);
void	chunk_sort2(t_ps *ps, t_chunk *chunk);
void	chunk_sort3(t_ps *ps, t_chunk *chunk);

static void	get_pivots(t_chunk *chunk, uint32_t *p, uint32_t *q)
{
	uint32_t	min;
	uint32_t	max;
	uint32_t	one_third;

	min = chunk_min(*chunk);
	max = chunk_max(*chunk);
	one_third = chunk->len / 3;
	*p = min + one_third - 1;
	*q = min + one_third * 2 - 1;
	if (chunk->len % 3 == 2)
		*q = u32min(*q + 1, max - 1);
}

static void	split_chunk(t_ps *ps, t_chunk *chunk, t_chunk out[3])
{
	uint32_t	p;
	uint32_t	q;
	t_node		*node;

	get_pivots(chunk, &p, &q);
	while (chunk->len != 0)
	{
		node = chunk_top_node(chunk);
		if (node->target_pos <= p)
			chunk_push(ps, chunk, &out[low]);
		else if (node->target_pos <= q)
			chunk_push(ps, chunk, &out[mid]);
		else
			chunk_push(ps, chunk, &out[high]);
	}
}

static void	final_sort(t_ps *ps, t_chunk *chunk)
{
	if (ps->a.head->target_pos > ps->a.head->next->target_pos)
		sort3_a_start(ps,
			chunk_max((t_chunk){.len = usizemin(3, ps->a.len),
				.first = ps->a.head, .stack = &ps->a, .type = high}));
	if (chunk->len == 0)
		return ;
	if (chunk->len == 1)
	{
		if (chunk->first != chunk->stack->head)
			rrx(chunk->stack);
		px(chunk->stack, &ps->a);
	}
	else if (chunk->len == 2)
		chunk_sort2(ps, chunk);
	else
		chunk_sort3(ps, chunk);
}

static void	sort_recursive(t_ps *ps, t_chunk chunk)
{
	t_chunk	chunks[3];

	if (chunk.len <= 3)
	{
		final_sort(ps, &chunk);
		return ;
	}
	chunks[high] = chunk_empty(high);
	chunks[mid] = chunk_empty(mid);
	chunks[low] = chunk_empty(low);
	split_chunk(ps, &chunk, chunks);
	sort_recursive(ps, chunks[high]);
	sort_recursive(ps, chunks[mid]);
	sort_recursive(ps, chunks[low]);
}

void	sort(t_ps *ps)
{
	if (ps->a.len <= 5)
	{
		stack_sort_upto5(&ps->a, &ps->b);
		return ;
	}
	sort_recursive(ps, (t_chunk){.first = ps->a.head, .len = ps->a.len,
		.stack = &ps->a, .type = high});
}
