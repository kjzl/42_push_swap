/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:30:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:37 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

t_bool	rra(t_stack *a)
{
	if (a->len < 2)
		return (FALSE);
	stack_rrotate(a);
	print_sort_op(op_rra);
	return (TRUE);
}

t_bool	rrb(t_stack *b)
{
	if (b->len < 2)
		return (FALSE);
	stack_rrotate(b);
	print_sort_op(op_rrb);
	return (TRUE);
}

t_bool	rrx(t_stack *s)
{
	if (s->id == stack_a)
		return (rra(s));
	else
		return (rrb(s));
}

void	rrx_n(t_stack *s, size_t n)
{
	while (n--)
		rrx(s);
}

t_bool	rrr(t_stack *s1, t_stack *s2)
{
	if (s1->len < 2 || s2->len < 2)
		return (FALSE);
	stack_rrotate(s1);
	stack_rrotate(s2);
	print_sort_op(op_rrr);
	return (TRUE);
}

void	rrr_n(t_stack *s1, t_stack *s2, size_t n)
{
	while (n--)
		rrr(s1, s2);
}
