/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_serialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:26:41 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 06:18:19 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_serialize_util.h"

t_str	display_stacks(const t_stack *a, const t_stack *b)
{
	t_vec	a_strs;
	t_vec	b_strs;
	int32_t		columns_width;
	t_str	tmp;

	columns_width = ft_umax(int_width(stack_max(a)), int_width(stack_max(b)));
	a_strs = vec_mapi(a, map_itoa, sizeof(t_str), &columns_width);
	b_strs = vec_mapi(b, map_itoa, sizeof(t_str), &columns_width);
	tmp = str_new_repeat("_", 1, columns_width);
	vec_push_front(&a_strs, &tmp);
	tmp = str_new_repeat("_", 1, columns_width);
	vec_push_front(&b_strs, &tmp);
	tmp = str_new_clone("a");
	str_pad(&tmp, columns_width, ' ');
	vec_push_front(&a_strs, &tmp);
	tmp = str_new_clone("b");
	str_pad(&tmp, columns_width, ' ');
	vec_push_front(&b_strs, &tmp);
	return (merge_stack_strs(&a_strs, &b_strs, columns_width));
}
