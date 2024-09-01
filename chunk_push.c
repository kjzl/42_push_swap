/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:33:06 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:33:13 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunk_push_to_high(t_ps *ps, t_chunk *from, t_chunk *to)
{
	t_node	*to_push;

	to_push = chunk_top_node(from);
	if (to->len == 0)
		to->first = to_push;
	to->len++;
	to->stack = &ps->a;
	if (to_push == from->first)
		from->first = from->first->next;
	from->len--;
	if (to_push != from->stack->head)
		rrx(from->stack);
	else if (from->stack->id == stack_a)
		ra(&ps->a);
	if (from->stack->id == stack_b)
		pa(&ps->a, &ps->b);
	if (to_push == to->stack->head)
		to->first = to_push;
}

static void	chunk_push_to_mid(t_ps *ps, t_chunk *from, t_chunk *to)
{
	t_node	*to_push;

	to_push = chunk_top_node(from);
	if (to->len == 0)
	{
		to->first = to_push;
		to->stack = &ps->b;
		if (from->stack->id == stack_b)
			to->stack = &ps->a;
	}
	to->len++;
	if (to_push == from->first)
		from->first = from->first->next;
	from->len--;
	if (to_push != from->stack->head)
		rrx(from->stack);
	px(from->stack, to->stack);
	if (to->stack->id == stack_a)
		ra(&ps->a);
	else
		to->first = to_push;
}

static void	chunk_push_to_low(t_ps *ps, t_chunk *from, t_chunk *to)
{
	t_node	*to_push;
	t_bool	need_rotate;

	to_push = chunk_top_node(from);
	if (to->len == 0)
		to->first = to_push;
	to->len++;
	to->stack = &ps->b;
	if (to_push == from->first)
		from->first = from->first->next;
	from->len--;
	need_rotate = (from->stack->id == stack_a || to_push == to->stack->head);
	if (to_push != from->stack->head)
		rrx(from->stack);
	px(from->stack, to->stack);
	if (need_rotate)
		rx(to->stack);
	if (to_push == to->stack->head)
		to->first = to_push;
}

void	chunk_push(t_ps *ps, t_chunk *from, t_chunk *to)
{
	if (to->type == high)
		chunk_push_to_high(ps, from, to);
	else if (to->type == mid)
		chunk_push_to_mid(ps, from, to);
	else if (to->type == low)
		chunk_push_to_low(ps, from, to);
}
