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
#include <stdlib.h>

const int32_t	*stack_get(const t_stack *stack)
{
	return (vec_get(&stack->s));
}

const int32_t	*stack_get_at(const t_stack *stack, size_t index)
{
	return (vec_get_at(&stack->s, index));
}

const int32_t	*stack_get_top(const t_stack *stack)
{
	return (vec_get_last(&stack->s));
}

const int32_t	*stack_get_bottom(const t_stack *stack)
{
	return (vec_get(&stack->s));
}

t_bool	exec_sort_op(t_stack *a, t_stack *b, t_sort_op op)
{
	static t_sort_op_fn	op_fn[] = {_sa, _sb, ss, pa, pb, _ra, _rb, _rr, _rra,
			_rrb, _rrr};

	return (op_fn[op](a, b));
}

void	stack_push(t_stack *stack, t_node *node)
{
	t_node	*old_head;

	old_head = stack->head;
	stack->head = node;
	if (old_head == 0)
	{
		stack->head->next = stack->head;
		stack->head->prev = stack->head;
		return ;
	}
	stack->head->next = old_head;
	stack->head->prev = old_head->prev;
	old_head->prev = stack->head;
	if (old_head->next == old_head)
		old_head->next = stack->head;
}

t_bool	stack_pushv(t_stack *stack, int32_t val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == 0)
		return (FALSE);
	node->val = val;
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
	old_head->next = 0;
	old_head->prev = 0;
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

// TODO (this is ai generated code)
t_bool	stack_swap_nodes(t_node *a, t_node *b)
{

	if (a == b)
		return (FALSE);
	a->prev->next = b;
	a->next->prev = b;
	b->prev->next = a;
	b->next->prev = a;
	a->prev = b->prev;
	a->next = b->next;
	b->prev = a->prev;
	b->next = a->next;
	return (TRUE);
}

t_bool	stack_rotate(t_stack *stack)
{
	if (stack->head == 0)
		return (FALSE);
	stack->head = stack->head->next;
	return (TRUE);
}

t_bool	stack_rrotate(t_stack *stack)
{
	if (stack->head == 0)
		return (FALSE);
	stack->head = stack->head->prev;
	return (TRUE);
}

/// UB if the stack is empty.
t_entry	stack_min(t_stack *s)
{
	int32_t	min;
	size_t	min_i;
	size_t	i;
	int32_t	*arr;

	arr = stack_get(&s->s);
	min = *arr;
	i = 1;
	while (i < s->s.len)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_i = i;
		}
		i++;
	}
	return ((t_entry){min_i, min});
}

/// UB if the stack is empty.
t_entry	stack_max(t_stack *s)
{
	int32_t	max;
	size_t	max_i;
	size_t	i;
	int32_t	*arr;

	arr = stack_get(s);
	max = *arr;
	i = 1;
	while (i < s->s.len)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
		i++;
	}
	return ((t_entry){max_i, max});
}

t_entry	entry_by_val(t_stack *s, uint32_t val)
{
	size_t	i;
	int32_t	*arr;
	while (i < s->s.len)
	{
		if (arr[i] == val)
			return ((t_entry){i, val});
		i++;
	}
}

t_entry	entry_at(t_stack *s, size_t i)
{
	return ((t_entry){i, *stack_get_at(s, i)});
}

t_bool	stack_is_sorted(t_stack *s)
{
	size_t	max_i;
	size_t	i;
	int32_t	*arr;

	if (s->len < 2)
		return (TRUE);
	max_i = stack_max(s).index;
	i = 0;
	arr = stack_get(s);
	while (i < s->len)
	{
		if (arr[i] < arr[i + 1])
			return (FALSE);
		i++;
		if (i == max_i)
			i++;
	}
	return (max_i == s->len - 1 || arr[s->len - 1] > arr[0]);
}

// TODO create methods sa/sb/ss/pa/pb/ra/rb/rr/rra/rrb/rrr for just one t_stack and grab stack_id from struct
void	stack_sort3(t_stack *a, t_stack *b)
{
	size_t	max_i;
	size_t	min_i;
	size_t	i;

	if (a-> < 3)
		return ;
	max_i = stack_max(s).index;
	min_i = stack_min(s).index;

}
