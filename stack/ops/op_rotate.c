/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:24:43 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:25 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

t_bool	ra(t_stack *a)
{
	if (a->len < 2)
		return (FALSE);
	stack_rotate(a);
	print_sort_op(op_ra);
	return (TRUE);
}

t_bool	rb(t_stack *b)
{
	if (b->len < 2)
		return (FALSE);
	stack_rotate(b);
	print_sort_op(op_rb);
	return (TRUE);
}

t_bool	rx(t_stack *s)
{
	if (s->id == stack_a)
		return (ra(s));
	else
		return (rb(s));
}

t_bool	rr(t_stack *s1, t_stack *s2)
{
	if (s1->len < 2 || s2->len < 2)
		return (FALSE);
	stack_rotate(s1);
	stack_rotate(s2);
	print_sort_op(op_rr);
	return (TRUE);
}
