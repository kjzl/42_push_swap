#include "stack.h"
#include <stdlib.h>

void	stack_clear(t_stack	*stack)
{
	t_node	*node;

	if (stack->head == 0)
		return ;
	node = stack->head;
	while (node->next != stack->head)
	{
		node = node->next;
		free(node->prev);
	}
	free(node);
	stack->head = 0;
	stack->len = 0;
}
