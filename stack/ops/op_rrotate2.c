/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:01:43 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 18:02:09 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

void	rrx_n(t_stack *s, size_t n)
{
	while (n--)
		rrx(s);
}

void	rrr_n(t_stack *s1, t_stack *s2, size_t n)
{
	while (n--)
		rrr(s1, s2);
}
