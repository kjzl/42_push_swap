/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_serialize_util2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:51:57 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 06:14:18 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	str_pad(t_str *str, size_t min_len, char c)
{
	if (min_len > str->len)
		str_insertn(str, 0, c, min_len - str->len);
}

void	map_itoa(const t_vec *from, t_vec *to, size_t i, int32_t *min_str_width)
{
	t_str	*str_to;

	str_to = (t_str *)vec_get_at(to, i);
	*str_to = str_itoa(*stack_get_at(from, i), str_base10());
	str_pad(str_to, *min_str_width, ' ');
}

t_bool	merge_stack_entries(t_vec a_pop, t_vec b_pop, t_str *out_str,
		size_t columns_width)
{
	if (a_pop.len == 0 && b_pop.len == 0)
		return (FALSE);
	if (a_pop.len > 0)
		*out_str = *(t_str *)vec_get(&a_pop);
	else
		*out_str = str_new_repeat(" ", 1, columns_width);
	str_push(out_str, ' ');
	if (b_pop.len > 0)
		str_pushstr2(out_str, *(t_str *)vec_get(&b_pop));
	else
		str_pushn(out_str, ' ', columns_width);
	vec_destroy(&a_pop, 0);
	vec_destroy(&b_pop, str_destroy);
	return (TRUE);
}

t_str	merge_stack_strs(t_vec *a_strs, t_vec *b_strs, size_t columns_width)
{
	t_vec	out_arr;
	t_str	out;
	t_str	sep;

	out_arr = vec_empty_with_capacity(sizeof(t_str), ft_umax(a_strs->len,
				b_strs->len));
	if (out_arr.mem_err)
		return (str_empty());
	while (merge_stack_entries(vec_pop(a_strs), vec_pop(b_strs),
			vec_get(&out_arr) + out_arr.len * sizeof(t_str), columns_width))
		++out_arr.len;
	vec_destroy(a_strs, str_destroy);
	vec_destroy(b_strs, str_destroy);
	sep = str_new_clone("\n");
	out = vec_join_strs(&out_arr, &sep);
	vec_destroy(&out_arr, str_destroy);
	str_destroy(&sep);
	return (out);
}
