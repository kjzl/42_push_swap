/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:36:39 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:36:40 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
