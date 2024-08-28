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

#include "../stack.h"
#include "../../libft/libft.h"

const char	*sort_op_str(t_sort_op op)
{
	static const char * const	op_strs[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
			"rra", "rrb", "rrr"};

	return (op_strs[op]);
}

void	print_sort_op(t_sort_op op)
{
	ft_putendl_fd(sort_op_str(op), STDOUT);
}

t_bool	sort_op_parse(t_str_slice str, t_sort_op *out)
{
	static const uint8_t	hash_table[1 << 8] = {
		[2 + ((2 * 's' - 'a' + 0) % (1 << 6))] = op_sa,
		[2 + ((2 * 's' - 'b' + 0) % (1 << 6))] = op_sb,
		[2 + ((2 * 's' - 's' + 0) % (1 << 6))] = op_ss,
		[2 + ((2 * 'p' - 'a' + 0) % (1 << 6))] = op_pa,
		[2 + ((2 * 'p' - 'b' + 0) % (1 << 6))] = op_pb,
		[2 + ((2 * 'r' - 'a' + 0) % (1 << 6))] = op_ra,
		[2 + ((2 * 'r' - 'b' + 0) % (1 << 6))] = op_rb,
		[2 + ((2 * 'r' - 'r' + 0) % (1 << 6))] = op_rr,
		[3 + ((2 * 'r' - 'r' + 'a') % (1 << 6))] = op_rra,
		[3 + ((2 * 'r' - 'r' + 'b') % (1 << 6))] = op_rrb,
		[3 + ((2 * 'r' - 'r' + 'r') % (1 << 6))] = op_rrr
	};
	uint8_t					op;

	if (str.len < 2)
		return (FALSE);
	op = hash_table[str.len + (2 * str.str[0] - str.str[1]
		+ ft_isalpha(str.str[2]) * str.str[2]) % (1 << 6)];
	if (op == 0 || ft_strncmp(str.str, sort_op_str((t_sort_op)op), str.len))
		return (FALSE);
	*out = (t_sort_op)op;
	return (TRUE);
}
