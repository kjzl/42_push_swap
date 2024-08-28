#include "stack.h"
#include <stdint.h>
#include <stdlib.h>

void	stack_push(t_stack *stack, t_node *node)
{
	t_node	*old_head;

	old_head = stack->head;
	stack->head = node;
	stack->len++;
	if (old_head == 0)
	{
		stack->head->next = stack->head;
		stack->head->prev = stack->head;
		return ;
	}
	stack->head->next = old_head;
	stack->head->prev = old_head->prev;
	old_head->prev->next = stack->head;
	old_head->prev = stack->head;
	if (old_head->next == old_head)
		old_head->next = stack->head;
	if (stack->len > STACK_FAST_NEXT_INTERVAL)
		node_at_slow(stack, stack->len - 1 - STACK_FAST_NEXT_INTERVAL)->fast_next = stack->head;
}

t_bool	stack_pushv(t_stack *stack, int32_t val, uint32_t target_pos)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == 0)
		return (FALSE);
	node->val = val;
	node->target_pos = target_pos;
	stack_push(stack, node);
	return (TRUE);
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*old_head;

	if (stack->head == 0)
		return (0);
	old_head = stack->head;
	if (old_head->next == old_head)
		stack->head = 0;
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = old_head->prev;
		old_head->prev->next = stack->head;
	}
	stack->len--;
	old_head->next = 0;
	old_head->prev = 0;
	old_head->fast_next = 0;
	return (old_head);
}

/// @warning will segfault if the stack is empty.
int32_t stack_popv(t_stack *stack)
{
	t_node	*node;
	int32_t	val;

	node = stack_pop(stack);
	val = node->val;
	free(node);
	return (val);
}

void	node_swapv(t_node *a, t_node *b)
{
	int32_t		val;
	uint32_t	target_pos;

	val = a->val;
	a->val = b->val;
	b->val = val;
	target_pos = a->target_pos;
	a->target_pos = b->target_pos;
	b->target_pos = target_pos;
}
