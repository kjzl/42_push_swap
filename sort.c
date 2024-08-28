#include "libft.h"
#include "libft/ft_types.h"
#include "push_swap.h"
#include "stack/stack.h"
#include <stdint.h>

// static void	get_pivot(t_chunk *chunk, uint32_t *p, uint32_t *q)
// {
// 	uint32_t	min;
// 	uint32_t	max;
// 	float		p_float;
// 	float		q_float;

// 	min = chunk_min(chunk);
// 	max = chunk_max(chunk);
// 	p_float = (float)min + (float)(max - min) / 3.0;
// 	q_float = (float)min + (float)(max - min) / 3.0 * 2.0;
// 	*p = (uint32_t)p_float;
// 	*q = (uint32_t)q_float;
// 	// if (p_float - (float)*p >= 0.5f)
// 	// 	*p += 1;
// 	if (q_float - (float)*q >= 0.5f)
// 		*q += 1;
// 	*q = u32min(*q, max - 1);
// 	// *p = u32min(*p, *q - 1);
// 	if (*q == max - 1)
// 	{
// 		*p = u32min(*p - 1, min);
// 		*q = u32max(*q - 1, *p + 1);
// 	}
// }

// /// @brief Get the pivot values for the 3-way quicksort
// static void	get_pivot(t_chunk *chunk, uint32_t *q)
// {

// }

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
	// else if ((max - min) % 3 == 1)
	// {
	// 	*p = min + one_third - 1;
	// 	*q = min + one_third * 2;
	// }
	// else /*if ((max - min) % 3 == 2)*/
	// {
	// 	*p = min + one_third;
	// 	*q = min + one_third * 2;
	// }
}

static void	split_chunk(t_ps *ps, t_chunk *chunk, t_chunk out[3])
{
	uint32_t	p;
	uint32_t	q;
	t_node		*node;

	get_pivots(chunk, &p, &q);
	// ft_printf_fd(STDERR, "p: %u, q: %u\n", p, q);
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

static void	chunk_debug_print(t_chunk *chunk)
{
	t_node	*node;
	size_t	i;

	// ft_printf_fd(STDERR, "chunk: len = %d\n", chunk->len);
	i = 0;
	node = chunk->first;
	while (i < chunk->len)
	{
		// ft_printf_fd(STDERR, "%d\n", node->target_pos);
		node = node->next;
		i++;
	}
}

static void	final_sort(t_ps *ps, t_chunk *chunk)
{
	// ft_printf_fd(STDERR, "final_sort for ");
	chunk_debug_print(chunk);
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

// static void	stack_print(t_stack *s)
// {
// 	size_t	i;
// 	t_node	*node;
// 	const char *stack_name;

// 	i = 0;
// 	node = s->head;
// 	if (s->id == stack_a)
// 		stack_name = "A";
// 	else
// 		stack_name = "B";

// 	// ft_printf_fd(STDERR, "%s: len = %d\n", stack_name, (int32_t)s->len);
// 	while (i < s->len)
// 	{
// 		// ft_printf_fd(STDERR, "%d\n", node->val);
// 		node = node->next;
// 		i++;
// 	}
// }

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
	// ft_printf_fd(STDERR, "SORT HIGH ");
	chunk_debug_print(&chunks[high]);
	sort_recursive(ps, chunks[high]);
	// ft_printf_fd(STDERR, "SORT MID: ");
	chunk_debug_print(&chunks[mid]);
	sort_recursive(ps, chunks[mid]);
	// ft_printf_fd(STDERR, "SORT LOW: ");
	chunk_debug_print(&chunks[low]);
	sort_recursive(ps, chunks[low]);
	// stack_print(&ps->a);
	// stack_print(&ps->b);
}

void	sort(t_ps *ps)
{
	if (ps->a.len <= 5)
	{
		stack_sort(&ps->a, &ps->b);
		return;
	}
	sort_recursive(ps, (t_chunk){.first = ps->a.head, .len = ps->a.len,
			.stack = &ps->a, .type = high});
}
