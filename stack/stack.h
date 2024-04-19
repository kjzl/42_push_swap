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

# include "../libft/libft.h"

/// @brief A stack of integers.
typedef t_vec	t_stack;

typedef enum e_sort_op
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}				t_sort_op;

typedef t_bool	(*t_sort_op_fn)(t_stack *a, t_stack *b);

t_vec			parse_stack(const char *str);
t_str			display_stacks(const t_stack *a, const t_stack *b);

int				*stack_get(const t_vec *vec);
int				*stack_get_at(const t_vec *vec, size_t index);
int				*stack_get_last(const t_vec *vec);

t_bool			exec_sort_op(t_stack *a, t_stack *b, t_sort_op op);
t_bool			_sa(t_stack *a, t_stack *b);
t_bool			_sb(t_stack *a, t_stack *b);
t_bool			_ss(t_stack *a, t_stack *b);
t_bool			_pa(t_stack *a, t_stack *b);
t_bool			_pb(t_stack *a, t_stack *b);
t_bool			_ra(t_stack *a, t_stack *b);
t_bool			_rb(t_stack *a, t_stack *b);
t_bool			_rr(t_stack *a, t_stack *b);
t_bool			_rra(t_stack *a, t_stack *b);
t_bool			_rrb(t_stack *a, t_stack *b);
t_bool			_rrr(t_stack *a, t_stack *b);

t_str			display_sort_op(t_sort_op op);
t_bool			parse_sort_op(const char *str, t_sort_op *out);

#endif
