#include "push_swap.h"

static void	chunk_sort2_b(t_ps *ps, t_chunk *chunk)
{
	if (chunk->first == chunk->stack->head)
	{
		if (ps->b.head->target_pos < ps->b.head->next->target_pos)
			sb(&ps->b);
		pa(&ps->a, &ps->b);
		pa(&ps->a, &ps->b);
	}
	else
	{
		if (chunk->first->target_pos > chunk->first->next->target_pos)
		{
			rrb(&ps->b);
			rrb(&ps->b);
			pa(&ps->a, &ps->b);
			pa(&ps->a, &ps->b);
		}
		else
		{
			rrb(&ps->b);
			pa(&ps->a, &ps->b);
			rrb(&ps->b);
			pa(&ps->a, &ps->b);
		}
	}
}

/// Sorts the chunk into the top of stack A
void	chunk_sort2(t_ps *ps, t_chunk *chunk)
{
	if (chunk->stack->id == stack_a)
	{
		if (chunk->first != chunk->stack->head)
			rrx_n(chunk->stack, 2);
		if (ps->a.head->target_pos > ps->a.head->next->target_pos)
			sx(chunk->stack);
	}
	else
		chunk_sort2_b(ps, chunk);
}
