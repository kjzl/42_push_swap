/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:36:52 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:36:53 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
