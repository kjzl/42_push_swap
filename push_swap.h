/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:33:43 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/01 17:40:51 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# pragma once

# include "stack/stack.h"

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
}			t_ps;

void	sort(t_ps *ps);
void	chunk_push(t_ps *ps, t_chunk *from, t_chunk *to);

#endif
