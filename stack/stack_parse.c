/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 04:28:24 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 04:30:17 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static size_t	isspace_pattern(t_str_slice sl)
{
	size_t	i;

	i = 0;
	while (i < sl.len && ft_isspace(sl.str[i]))
		i++;
	return (i);
}

/// @brief Maps a string to an integer.
/// @param from The str_view vec.
/// @param to The int32_t vec.
/// @param i The index of the element.
/// @param parse_err A pointer to a boolean that signals a conversion error.
static void	map_atoi(const t_vec *from, t_vec *to, size_t i, void *err_i)
{
	if (*(ssize_t *)err_i == -1)
		if (!strsl_atoi(*(t_str_slice *)vec_get_at(from, i),
				base10(), vec_get_at(to, i), OFB_ERROR))
			*(ssize_t *)err_i = i;
}

/// @brief Parses a string into a stack in reverse order.
/// @param str The string to parse.
/// @return The stack or empty stack if input conversion failed.
/// @warning Check the error flag for memory allocation errors.
t_stack	parse_stack_str(t_str_slice sl)
{
	t_vec	split;
	t_vec	stack_a;
	ssize_t	err_i;

	err_i = -1;
	split = strsl_split_where(sl, isspace_pattern);
	stack_a = vec_mapi(&split, map_atoi, sizeof(int32_t), &err_i);
	if (err_i != -1)
	{
		vec_destroy(&stack_a, 0);
		ft_printf_fd(2, "Expected a signed 32-bit decimal. "
				"Error caused by argument at index %u", (uint32_t)err_i);
	}
	vec_destroy(&split, 0);
	vec_reverse(&stack_a);
	return (stack_a);
}

/// @brief Parses multiple base10 strings into a stack of u32.
/// @param strs The strings to parse.
/// @param strc The number of strings.
/// @return The stack or empty stack if input conversion failed.
t_stack	parse_stack(const char **strs, size_t strc)
{
	t_vec	stack_a;
	size_t	i;

	stack_a = vec_empty_with_capacity(sizeof(int32_t), strc);
	if (stack_a.mem_err)
		return (stack_a);
	i = 0;
	while (i < strc)
	{
		if (!strsl_atoi(cstr_view(strs[i]), base10(),
			(int32_t *)vec_get_next_uninit_incr_len(&stack_a), OFB_ERROR))
			break;
		i++;
	}
	if (i == strc)
		return (stack_a);
	vec_destroy(&stack_a, 0);
	ft_printf_fd(2, "Expected a signed 32-bit decimal. "
			"Error caused by argument at index %u", (uint32_t)i);
	return (stack_a);
}
