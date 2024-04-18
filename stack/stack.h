/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:58:53 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:36:58 by kwurster         ###   ########.fr       */
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

int				*stack_get(const t_vec *vec);
int				*stack_get_at(const t_vec *vec, size_t index);
int				*stack_get_last(const t_vec *vec);

t_bool			exec_sort_op(t_stack *a, t_stack *b, t_sort_op op);
t_bool			sa(t_stack *a, t_stack *b);
t_bool			sb(t_stack *a, t_stack *b);
t_bool			ss(t_stack *a, t_stack *b);
t_bool			pa(t_stack *a, t_stack *b);
t_bool			pb(t_stack *a, t_stack *b);
t_bool			ra(t_stack *a, t_stack *b);
t_bool			rb(t_stack *a, t_stack *b);
t_bool			rr(t_stack *a, t_stack *b);
t_bool			rra(t_stack *a, t_stack *b);
t_bool			rrb(t_stack *a, t_stack *b);
t_bool			rrr(t_stack *a, t_stack *b);

#endif
