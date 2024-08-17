/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_serialize_util.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 04:04:28 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 06:15:36 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int32_t		stack_max(const t_stack *stack);
int32_t		stack_min(const t_stack *stack);
int32_t		int_width(int32_t i);
void	str_pad(t_str *str, size_t min_len, char c);
void	map_itoa(const t_vec *from, t_vec *to, size_t i, int32_t *min_str_width);
t_bool	merge_stack_entries(t_vec a_pop, t_vec b_pop, t_str *out_str,
			size_t columns_width);
t_str	merge_stack_strs(t_vec *a_strs, t_vec *b_strs, size_t columns_width);
