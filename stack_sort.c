/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:22:08 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 18:09:19 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	stack_sort2(t_stack *s)
{
	if (s->len != 2)
		return ;
	if (s->head->val > s->head->next->val)
		sx(s);
}

void	stack_sort4(t_stack *to_sort, t_stack *other)
{
	t_entry	max;
	t_entry	push;
	t_bool	rev_rot;

	if (to_sort->len != 4)
		return ;
	max = stack_max(to_sort);
	push = stack_min(to_sort);
	if (usizemin(node_dist(max) + 1, node_rdist(to_sort, max) + 1)
		< usizemin(node_dist(push), node_rdist(to_sort, push)))
	{
		rev_rot = (node_dist(max) > node_rdist(to_sort, max));
		push = max;
	}
	else
		rev_rot = (node_dist(push) > node_rdist(to_sort, push));
	while (rev_rot && push.node != to_sort->head)
		rrx(to_sort);
	while (!rev_rot && push.node != to_sort->head)
		rx(to_sort);
	px(to_sort, other);
	stack_sort3(to_sort);
	px(other, to_sort);
	if (stack_max(to_sort).index == 0)
		rx(to_sort);
}

void	stack_sort_upto5(t_stack *to_sort, t_stack *other)
{
	if (to_sort->len == 2)
		stack_sort2(to_sort);
	else if (to_sort->len == 3)
		stack_sort3(to_sort);
	else if (to_sort->len == 4)
		stack_sort4(to_sort, other);
	else if (to_sort->len == 5)
		stack_sort5(to_sort, other);
}
