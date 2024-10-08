/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:36:45 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 18:05:03 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "../libft/libft.h"

t_stack	stack_new(t_stack_id id)
{
	t_stack	stack;

	stack.head = 0;
	stack.len = 0;
	stack.id = id;
	return (stack);
}

static int32_t	cmp_i32(const void *a, const void *b)
{
	if (*(int32_t *)a < *(int32_t *)b)
		return (-1);
	if (*(int32_t *)a > *(int32_t *)b)
		return (1);
	return (0);
}

static void	sort_vec_and_set_target_pos(t_vec *vec, t_stack *stack)
{
	size_t	i;
	int32_t	*data;

	if (stack->len != vec->len)
		return ;
	i = 0;
	data = vec_get(vec);
	arr_qsort(data, vec->len, vec->element_size, cmp_i32);
	while (i < vec->len)
	{
		node_by_val(stack, data[i])->target_pos = i;
		i++;
	}
}

/// @brief Create a stack from a vector.
/// @param vec The int32_t vector to create the stack from.
/// @param id The stack id.
/// @return The stack created from the vector.
/// @note The last element of the vec will be the top/head of the stack.
/// @note The vector is destroyed in the process.
/// @note If the stack cant be created, the vector is destroyed
/// and the stack is cleared.
t_stack	stack_from_vec(t_vec *vec, t_stack_id id)
{
	t_stack	stack;
	int32_t	*data;
	size_t	i;

	stack = stack_new(id);
	data = vec_get(vec);
	i = 0;
	while (i < vec->len)
	{
		if (!stack_pushv(&stack, data[i], 0))
		{
			stack_clear(&stack);
			break ;
		}
		i++;
	}
	sort_vec_and_set_target_pos(vec, &stack);
	vec_destroy(vec, 0);
	return (stack);
}
