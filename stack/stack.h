/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:58:53 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 06:21:31 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# pragma once

# include "../libft/libft.h"

typedef enum e_stack_id
{
	a,
	b
}				t_stack_id;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int32_t			val;
}					t_node;

typedef struct s_stack
{
	t_node		*head;
	t_stack_id	id;
}					t_stack;

// typedef struct s_stack
// {
// 	t_vec		s;
// 	t_stack_id	id;
// }				t_stack;

typedef enum e_sort_op
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr
}				t_sort_op;

typedef struct s_entry
{
	size_t	index;
	t_node	*node;
}			t_entry;

typedef t_bool	(*t_sort_op_fn)(t_stack *a, t_stack *b);

t_stack			parse_stack_str(t_str_slice sl);
t_str			display_stacks(const t_stack *a, const t_stack *b);

const int32_t	*stack_get(const t_stack *stack);
const int32_t	*stack_get_at(const t_stack *stack, size_t index)
const int32_t	*stack_get_last(const t_vec *vec);

t_bool			exec_sort_op(t_stack *a, t_stack *b, t_sort_op op);
t_bool			sa(t_stack *a);
t_bool			_sa(t_stack *a, t_stack *b);
t_bool			sb(t_stack *b);
t_bool			_sb(t_stack *a, t_stack *b);
t_bool			ss(t_stack *a, t_stack *b);
t_bool			pa(t_stack *a, t_stack *b);
t_bool			pb(t_stack *a, t_stack *b);
t_bool			_ra(t_stack *a, t_stack *b);
t_bool			_rb(t_stack *a, t_stack *b);
t_bool			_rr(t_stack *a, t_stack *b);
t_bool			_rra(t_stack *a, t_stack *b);
t_bool			_rrb(t_stack *a, t_stack *b);
t_bool			_rrr(t_stack *a, t_stack *b);

t_str_slice		display_sort_op(t_sort_op op);
t_bool			parse_sort_op(const char *str, t_sort_op *out);

#endif
