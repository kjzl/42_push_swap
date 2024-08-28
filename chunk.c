#include "ft_types.h"
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

// from b to high = push on the head of A
// from a to high = push on the end of A
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
// from a mid (bottom) to mid
// from b to mid = push on the end of A
// from a to mid = push on the head of b
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

// from b mid to mid = push on the end of A
// from everywhere else to mid = push on the head of B
// static void	chunk_push_to_mid(t_ps *ps, t_chunk *from, t_chunk *to)
// {
// 	t_node	*first;
// 	t_node	*to_push;

// 	to_push = chunk_top_node(from);
// 	if (to->len == 0)
// 		to->first = to_push;
// 	to->len++;
// 	first = from->first;
// 	from->first = from->first->next;
// 	from->len--;
// 	if (from->stack->id == stack_b && from->type == mid)
// 		to->stack = &ps->a;
// 	else
// 		to->stack = &ps->b;
// 	if (first != from->stack->head)
// 		rrx(from->stack);
// 	px(from->stack, to->stack);
// 	if (to->stack->id == stack_a)
// 		ra(&ps->a);
// 	if (to_push == to->stack->head)
// 		to->first = to_push;
// }

// from b bottom to low = push on the head of B
// from everywhere else to low = push on the end of B
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

// from b low to low = push on the end of A
// from everywhere else to low = push on the end of B
// static void	chunk_push_to_low(t_ps *ps, t_chunk *from, t_chunk *to)
// {
// 	t_node	*first;
// 	t_node	*to_push;

// 	to_push = chunk_top_node(from);
// 	if (to->len == 0)
// 		to->first = to_push;
// 	to->len++;
// 	first = from->first;
// 	from->first = from->first->next;
// 	from->len--;
// 	if (from->stack->id == stack_a || from->type != low)
// 		to->stack = &ps->b;
// 	else
// 		to->stack = &ps->a;
// 	if (first != from->stack->head)
// 		rrx(from->stack);
// 	px(from->stack, to->stack);
// 	rx(to->stack);
// }

// pushing from other than a to high would always push on the head of A
// pushing from a to high would always push on the end of A
// pushing from b mid to mid would always push on the end of A
// pushing from b low to low would always push on the end of A
void	chunk_push(t_ps *ps, t_chunk *from, t_chunk *to)
{
	if (to->type == high)
		chunk_push_to_high(ps, from, to);
	else if (to->type == mid)
		chunk_push_to_mid(ps, from, to);
	else if (to->type == low)
		chunk_push_to_low(ps, from, to);
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
