/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:09:49 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:05 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

t_bool	sa(t_stack *a)
{
	if (a->len < 2)
		return (FALSE);
	node_swapv(a->head, a->head->next);
	print_sort_op(op_sa);
	return (TRUE);
}

t_bool	sb(t_stack *b)
{
	if (b->len < 2)
		return (FALSE);
	node_swapv(b->head, b->head->next);
	print_sort_op(op_sb);
	return (TRUE);
}

t_bool	sx(t_stack *s)
{
	if (s->id == stack_a)
		return (sa(s));
	else
		return (sb(s));
}

t_bool	ss(t_stack *s1, t_stack *s2)
{
	if (s1->len < 2 || s2->len < 2)
		return (FALSE);
	node_swapv(s1->head, s1->head->next);
	node_swapv(s2->head, s2->head->next);
	print_sort_op(op_ss);
	return (TRUE);
}
