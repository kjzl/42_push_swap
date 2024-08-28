#include "stack.h"

void	stack_rotate(t_stack *stack)
{
	if (stack->head != 0)
		stack->head = stack->head->next;
}

void	stack_rrotate(t_stack *stack)
{
	if (stack->head != 0)
		stack->head = stack->head->prev;
}
