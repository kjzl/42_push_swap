/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:59 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 04:31:12 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_types.h"
#include "libft.h"

t_bool	stack_valid(t_stack *s, const char *msg)
{
	t_node	*prev;
	t_node	*node;
	size_t	i;

	i = 0;
	(void)msg;
	node = s->head;
	prev = 0;
	if (s->head != 0)
	{
		while (TRUE)
		{
			if (node == s->head && prev != 0)
				break;
			// if (i == s->len)
				//ft_printf_fd(STDERR, "%s: i = %d; s->len shorter than actual length\n", msg, (int32_t)i);
			// if (i == s->len*2)
			// {
				//ft_printf_fd(STDERR, "%s: i = %d; ABORTING LOOP\n", msg, (int32_t)i);
			// 	return (FALSE);
			// }
			prev = node;
			node = node->next;
			i++;
			// if (prev != node->prev)
				//ft_printf_fd(STDERR, "%s: i = %d; prev != node->prev\n", msg, (int32_t)i);
		}
	}
	if (i != s->len)
	{
		//ft_printf_fd(STDERR, "%s: i = %d; i != s->len\n", msg, (int32_t)i);
		return (FALSE);
	}
	return (TRUE);
}

// t_bool	exec_sort_op(t_stack *a, t_stack *b, t_sort_op op)
// {
// 	static t_sort_op_fn	op_fn[] = {_sa, _sb, ss, pa, pb, _ra, _rb, _rr, _rra,
// 			_rrb, _rrr};

// 	return (op_fn[op](a, b));
// }

// t_entry	entry_by_val(t_stack *s, uint32_t val)
// {
// 	size_t	i;
// 	int32_t	*arr;
// 	while (i < s->s.len)
// 	{
// 		if (arr[i] == val)
// 			return ((t_entry){i, val});
// 		i++;
// 	}
// }
//

t_entry	entry_at(t_stack *s, size_t i)
{
	return ((t_entry){i, node_at(s, i)});
}

/// UB if the stack is empty.
t_entry	stack_min(t_stack *s)
{
	t_node	*min;
	size_t	min_i;
	size_t	i;
	t_node	*node;

	node = s->head;
	min = node;
	min_i = 0;
	i = 1;
	while (i < s->len)
	{
		node = node->next;
		if (node->val < min->val)
		{
			min = node;
			min_i = i;
		}
		i++;
	}
	return ((t_entry){min_i, min});
}

/// UB if the stack is empty.
t_entry	stack_max(t_stack *s)
{
	t_node	*max;
	size_t	max_i;
	size_t	i;
	t_node	*node;

	node = s->head;
	max = node;
	max_i = 0;
	i = 1;
	while (i < s->len)
	{
		node = node->next;
		if (node->val > max->val)
		{
			max = node;
			max_i = i;
		}
		i++;
	}
	return ((t_entry){max_i, max});
}

void	stack_min2(t_stack *s, t_entry *min1, t_entry *min2)
{
	size_t	i;
	t_node	*node;

	node = s->head->next;
	if (s->head->val < s->head->next->val)
	{
		*min1 = (t_entry){0, s->head};
		*min2 = (t_entry){1, s->head->next};
	}
	else
	{
		*min1 = (t_entry){1, s->head->next};
		*min2 = (t_entry){0, s->head};
	}
	i = 2;
	while (i < s->len)
	{
		node = node->next;
		if (node->val < min1->node->val)
		{
			*min2 = *min1;
			*min1 = (t_entry){i, node};
		}
		else if (node->val < min2->node->val)
			*min2 = (t_entry){i, node};
		i++;
	}
}

void	stack_max2(t_stack *s, t_entry *max1, t_entry *max2)
{
	size_t	i;
	t_node	*node;

	node = s->head->next;
	if (s->head->val > s->head->next->val)
	{
		*max1 = (t_entry){0, s->head};
		*max2 = (t_entry){1, s->head->next};
	}
	else
	{
		*max1 = (t_entry){1, s->head->next};
		*max2 = (t_entry){0, s->head};
	}
	i = 2;
	while (i < s->len)
	{
		node = node->next;
		if (node->val > max1->node->val)
		{
			*max2 = *max1;
			*max1 = (t_entry){i, node};
		}
		else if (node->val > max2->node->val)
			*max2 = (t_entry){i, node};
		i++;
	}
}

t_bool	stack_is_sorted(t_stack *s, t_bool at_head, size_t n)
{
	t_node	*node;
	size_t	i;

	if (s->len < 2)
		return (TRUE);
	if (at_head)
		node = s->head;
	else if (s->id == stack_a)
		node = stack_min(s).node;
	else
		node = stack_max(s).node;
	i = 0;
	while (i < s->len - 1 && i < n)
	{
		if (s->id == stack_a && node->val > node->next->val)
			return (FALSE);
		if (s->id == stack_b && node->val < node->next->val)
			return (FALSE);
		node = node->next;
		i++;
	}
	return (TRUE);
}

/// @brief Returns the distance of the node from the top of the stack.
size_t	node_dist(t_entry n)
{
	return (n.index);
}

/// @brief Returns the distance of the node from the top of the stack
/// when traversing the stack in reverse order.
size_t	node_rdist(t_stack *s, t_entry n)
{
	if (n.index == 0)
		return (0);
	return (s->len - n.index);
}

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

/// Returns wheter to reverse rotate the stack to push both of the elements
// TODO could be optimized to reduce max ops in sort5 from 9 to 8
// by not using a pair of min or max but rather use absolute min and max together
// this would probably need quite a bit of refactoring
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
		return max_dist > max_rdist;
	stack_min2(s, min1, min2);
	return min_dist > min_rdist;
}

void	stack_push_smallest_two(t_stack *from, t_stack *to)
{
	t_entry	min1;
	t_entry	min2;
	size_t	pushed;
	t_bool	rev_rot;

	if (from->len < 2)
		return ;
	rev_rot = stack_min2_or_max2(from, &min1, &min2);
	//ft_printf("min1: %d\n", min1.node->val);
	//ft_printf("min2: %d\n", min2.node->val);
	pushed = 0;
	while (pushed < 2)
	{
		if (from->head == min1.node || from->head == min2.node)
		{
			px(from, to);
			pushed++;
			continue;
		}
		if (rev_rot)
			rrx(from);
		else
			rx(from);
		stack_valid(from, "stack_push_smallest_two.1");
		stack_valid(to, "stack_push_smallest_two.2");
	}
	// if (to->head->val < to->head->next->val)
	// 	sx(to);
	// stack_valid(from, "stack_push_smallest_two.3");
	// stack_valid(to, "stack_push_smallest_two.4");
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

// t_sorted_slice stack_longest_sorted_slice(t_stack *s)
// {
// 	t_sorted_slice	slice;
// 	t_node			*runner;
// 	size_t			i;

// 	slice = (t_sorted_slice){.len = 1, .index = 0, .start = s->head, .end = s->head};
// 	runner = s->head->next;
// 	i = 1;
// 	while (i < s->len)
// 	{
// 		if (slice.end == runner->prev && runner->val > )
// 		if (runner->val > runner->prev->val)
// 		{
// 			if (slice.len < i - slice.index + 1)
// 				slice = (t_sorted_slice){.len = i - slice.index + 1, .index = slice.index, .node = slice.node};
// 		}
// 		else
// 		{
// 			slice = (t_sorted_slice){.len = 1, .index = i, .node = runner};
// 		}
// 		runner = runner->next;
// 		i++;
// 	}
// }

void	stack_rotate_sorted(t_stack *s)
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

t_bool	stack_easy_sort(t_stack *s)
{
	if (s->len < 2)
		return TRUE;
	else if (s->len == 2)
		stack_sort2(s);
	else if (s->len == 3)
		stack_sort3(s);
	else if (stack_is_sorted(s, FALSE, s->len))
		stack_rotate_sorted(s);
	else
		return FALSE;
	return TRUE;
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

void	stack_sort2(t_stack *s)
{
	if (s->len != 2)
		return ;
	if (s->head->val > s->head->next->val)
		sx(s);
}

// TODO maybe hardcode optimization for the one case in which this needs 6 ops
void stack_sort4(t_stack *to_sort, t_stack *other)
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

void	stack_sort_n(t_stack *to_sort, t_stack *other)
{
	(void)to_sort;
	(void)other;
}

void	stack_sort(t_stack *to_sort, t_stack *other)
{
	if (to_sort->len == 2)
		stack_sort2(to_sort);
	else if (to_sort->len == 3)
		stack_sort3(to_sort);
	else if (to_sort->len == 4)
		stack_sort4(to_sort, other);
	else if (to_sort->len == 5)
		stack_sort5(to_sort, other);
	else
		stack_sort_n(to_sort, other);
}
