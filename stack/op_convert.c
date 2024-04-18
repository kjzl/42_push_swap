/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:36:25 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 17:44:56 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_str	display_sort_op(t_sort_op op)
{
	static char	*op_strs[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};

	return (str_new_clone(op_strs[op]));
}

t_bool	parse_sort_op(const char *str, t_sort_op *out)
{
	if (ft_strncmp(str, "sa", 3) == 0)
		*out = sa;
	else if (ft_strncmp(str, "sb", 3) == 0)
		*out = sb;
	else if (ft_strncmp(str, "ss", 3) == 0)
		*out = ss;
	else if (ft_strncmp(str, "pa", 3) == 0)
		*out = pa;
	else if (ft_strncmp(str, "pb", 3) == 0)
		*out = pb;
	else if (ft_strncmp(str, "ra", 3) == 0)
		*out = ra;
	else if (ft_strncmp(str, "rb", 3) == 0)
		*out = rb;
	else if (ft_strncmp(str, "rr", 3) == 0)
		*out = rr;
	else if (ft_strncmp(str, "rra", 4) == 0)
		*out = rra;
	else if (ft_strncmp(str, "rrb", 4) == 0)
		*out = rrb;
	else if (ft_strncmp(str, "rrr", 4) == 0)
		*out = rrr;
	else
		return (FALSE);
	return (TRUE);
}
