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

static size_t	isspace_pattern(char *str)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

/// @brief Maps a string to an integer.
/// @param from The str_view vec.
/// @param to The int vec.
/// @param i The index of the element.
/// @param parse_err A pointer to a boolean that signals a conversion error.
static void	map_atoi(const t_vec *from, t_vec *to, size_t i, t_bool *parse_err)
{
	*parse_err = !str_atoi(*(t_str_view *)vec_get_at(from, i), str_base10(),
			vec_get_at(to, i), parse_err) && *parse_err;
}

/// @brief Parses a string into a stack in reverse order.
/// @param str The string to parse.
/// @return The stack or empty stack if input conversion failed.
/// @warning Check the error flag for memory allocation errors.
t_stack	parse_stack(const char *str)
{
	t_vec	split;
	t_vec	stack_a;
	t_bool	parse_err;

	parse_err = FALSE;
	split = str_split(str, isspace_pattern);
	stack_a = vec_mapi(&split, map_atoi, sizeof(int), &parse_err);
	if (parse_err)
		vec_destroy(&stack_a);
	vec_destroy(&split);
	vec_reverse(&stack_a);
	return (stack_a);
}
