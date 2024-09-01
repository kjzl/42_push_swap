/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:25:47 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 18:09:22 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	stack_rotate_sorted(t_stack *s)
{
	t_entry	min;

	if (s->len < 2)
		return ;
	min = stack_min(s);
	if (node_dist(min) > node_rdist(s, min))
		while (s->head != min.node)
			rrx(s);
	else
		while (s->head != min.node)
			rx(s);
}

/// Returns wheter to reverse rotate the stack to push both of the elements
// TODO could be optimized to reduce max ops in sort5 from 9 to 8
// by not using a pair of min or max but rather use absolute min and max
// together this would probably need quite a bit of refactoring
static t_bool	stack_min2_or_max2(t_stack *s, t_entry *min1, t_entry *min2)
{
	size_t	min_dist;
	size_t	min_rdist;
	size_t	max_dist;
	size_t	max_rdist;

	stack_min2(s, min1, min2);
	min_dist = usizemax(node_dist(*min1), node_dist(*min2));
	min_rdist = usizemax(node_rdist(s, *min1), node_rdist(s, *min2));
	stack_max2(s, min1, min2);
	max_dist = usizemax(node_dist(*min1), node_dist(*min2)) + 2;
	max_rdist = usizemax(node_rdist(s, *min1), node_rdist(s, *min2)) + 2;
	if (usizemin(max_dist, max_rdist) < usizemin(min_dist, min_rdist))
		return (max_dist > max_rdist);
	stack_min2(s, min1, min2);
	return (min_dist > min_rdist);
}

static void	stack_push_smallest_two(t_stack *from, t_stack *to)
{
	t_entry	min1;
	t_entry	min2;
	size_t	pushed;
	t_bool	rev_rot;

	if (from->len < 2)
		return ;
	rev_rot = stack_min2_or_max2(from, &min1, &min2);
	pushed = 0;
	while (pushed < 2)
	{
		if (from->head == min1.node || from->head == min2.node)
		{
			px(from, to);
			pushed++;
			continue ;
		}
		if (rev_rot)
			rrx(from);
		else
			rx(from);
	}
}

static void	stack_sort5_sort3(t_stack *to_sort, t_stack *other)
{
	if (stack_max(to_sort).node->next != stack_min(to_sort).node)
	{
		if (other->head->val < other->head->next->val)
			ss(to_sort, other);
		else
			sx(to_sort);
	}
	if (to_sort->head->val == stack_max(to_sort).node->val)
	{
		if (other->head->val < other->head->next->val && other->len == 2)
			rr(to_sort, other);
		else
			rx(to_sort);
	}
	else if (to_sort->head->next->val == stack_max(to_sort).node->val)
	{
		if (other->head->val < other->head->next->val && other->len == 2)
			rrr(to_sort, other);
		else
			rrx(to_sort);
	}
}

void	stack_sort5(t_stack *to_sort, t_stack *other)
{
	if (to_sort->len != 5)
		return ;
	if (stack_is_sorted(to_sort, FALSE, to_sort->len))
		return (stack_rotate_sorted(to_sort));
	stack_push_smallest_two(to_sort, other);
	stack_sort5_sort3(to_sort, other);
	if (other->head->val < other->head->next->val)
		sx(other);
	px(other, to_sort);
	px(other, to_sort);
	if (stack_max(to_sort).index != 4)
	{
		rx(to_sort);
		rx(to_sort);
	}
}
