/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:59 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 17:45:04 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	*stack_get(const t_vec *vec)
{
	return (vec_get(vec));
}

int	*stack_get_at(const t_vec *vec, size_t index)
{
	return (vec_get_at(vec, index));
}

int	*stack_get_last(const t_vec *vec)
{
	return (vec_get_last(vec));
}

t_bool	exec_sort_op(t_stack *a, t_stack *b, t_sort_op op)
{
	static t_sort_op_fn	op_fn[] = {_sa, _sb, _ss, _pa, _pb, _ra, _rb, _rr, _rra,
		_rrb, _rrr};

	return (op_fn[op](a, b));
}
