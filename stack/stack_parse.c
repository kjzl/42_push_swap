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

#include "ft_types.h"
#include "libft.h"
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

/// @brief Parses a string into a stack in reverse order (first will be top).
/// @param str The string to parse.
/// @return The stack or empty stack if input conversion failed.
/// @warning Check the error flag for memory allocation errors.
t_stack	parse_stack_str(t_str_slice sl)
{
	t_vec	split;
	t_vec	stack;
	ssize_t	err_i;

	err_i = -1;
	split = strsl_split_where(sl, isspace_pattern);
	stack = vec_mapi(&split, map_atoi, sizeof(int32_t), &err_i);
	// print the len of split and stack
	// ft_printf_fd(STDERR, "split len: %d\n", (int32_t)split.len);
	// ft_printf_fd(STDERR, "stack len: %d\n", (int32_t)stack.len);
	if (err_i != -1)
	{
		vec_destroy(&stack, 0);
		ft_printf_fd(STDERR, "Error\nExpected a signed 32-bit decimal. "
				"Error caused by argument at index %u.\n", (uint32_t)err_i);
	}
	else if (!split.mem_err && split.len < 2)
		ft_printf_fd(STDERR, "Error\nThe stack must be at least of size 2.\n");
	vec_destroy(&split, 0);
	vec_reverse(&stack);
	return (stack_from_vec(&stack, stack_a));
}

/// @brief Parses multiple base10 strings into a stack of u32.
/// @param strs The strings to parse.
/// @param strc The number of strings.
/// @return The stack or empty stack if input conversion failed.
t_stack	parse_stack(const char **strs, size_t strc)
{
	t_vec	stack;
	size_t	i;

	stack = vec_empty_with_capacity(sizeof(int32_t), strc);
	if (stack.mem_err)
		return (stack_new(stack_a));
	i = 0;
	while (i < strc)
	{
		if (!strsl_atoi(cstr_view(strs[i]), base10(),
			(int32_t *)vec_get_next_uninit_incr_len(&stack), OFB_ERROR))
			break;
		// ft_printf_fd(STDERR, "%u: %d\n", i, *(int32_t *)vec_get_at(&stack, i));
		i++;
	}
	vec_reverse(&stack);
	// ft_printf_fd(STDERR, "(reversed) FIRST: %d\n", *(int32_t *)vec_get(&stack));
	// ft_printf_fd(STDERR, "(reversed) LAST: %d\n", *(int32_t *)vec_get_last(&stack));
	if (i == strc)
		return (stack_from_vec(&stack, stack_a));
	vec_destroy(&stack, 0);
	ft_printf_fd(STDERR, "Error\nExpected a signed 32-bit decimal. "
			"Error caused by argument at index %u.\n", (uint32_t)i);
	return (stack_new(stack_a));
}
