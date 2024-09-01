/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:24:39 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:39:08 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort3(t_stack *s)
{
	t_entry	max;
	int32_t	maxv;

	if (s->len != 3)
		return ;
	max = stack_max(s);
	maxv = max.node->val;
	if (max.node->next != stack_min(s).node)
		sx(s);
	if (s->head->val == maxv)
		rx(s);
	else if (s->head->next->val == maxv)
		rrx(s);
}
