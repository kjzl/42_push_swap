/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:58:53 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/02 14:37:36 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/ft_types.h"
# pragma once

# define STACK_FAST_STEP 10

typedef enum e_stack_id
{
	stack_a,
	stack_b
}				t_stack_id;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*fast_next;
	int32_t			val;
	uint32_t		target_pos;
}					t_node;

/// A stack of integers (implemented as a fast-ptr circular double linked list).
/// The Top of the stack is the head.
typedef struct s_stack
{
	t_node		*head;
	size_t		len;
	t_stack_id	id;
}				t_stack;

typedef enum e_chunk_ty
{
	high,
	mid,
	low
}	t_chunk_ty;

typedef struct s_chunk
{
	t_stack		*stack;
	t_node		*first;
	size_t		len;
	t_chunk_ty	type;
}			t_chunk;

typedef enum e_sort_op
{
	op_sa = 1,
	op_sb = 2,
	op_ss = 3,
	op_pa = 4,
	op_pb = 5,
	op_ra = 6,
	op_rb = 7,
	op_rr = 8,
	op_rra = 9,
	op_rrb = 10,
	op_rrr = 11
}				t_sort_op;

typedef struct s_entry
{
	size_t	index;
	t_node	*node;
}			t_entry;

typedef t_bool	(*t_sort_op_fn)(t_stack *a, t_stack *b);

void		stack_sort2(t_stack *s);
void		stack_sort3(t_stack *s);
void		stack_sort4(t_stack *to_sort, t_stack *other);
void		stack_sort5(t_stack *to_sort, t_stack *other);
void		stack_sort_upto5(t_stack *to_sort, t_stack *other);

t_entry		stack_min(t_stack *s);
t_entry		stack_max(t_stack *s);
void		stack_min2(t_stack *s, t_entry *min1, t_entry *min2);
void		stack_max2(t_stack *s, t_entry *max1, t_entry *max2);

t_chunk		chunk_empty(t_chunk_ty type);
t_node		*chunk_top_node(t_chunk *chunk);
uint32_t	chunk_max(t_chunk chunk);
uint32_t	chunk_min(t_chunk chunk);

t_stack		parse_stack_str(t_str_slice sl);
t_stack		parse_stack(const char **strs, size_t strc);

size_t		node_dist(t_entry n);
size_t		node_rdist(t_stack *s, t_entry n);

t_node		*node_by_val(const t_stack *stack, int32_t val);
t_node		*node_at(const t_stack *stack, size_t index);
t_node		*node_at_slow(const t_stack *stack, size_t index);

t_stack		stack_new(t_stack_id id);
t_stack		stack_from_vec(t_vec *vec, t_stack_id id);
t_bool		stack_is_sorted(t_stack *s, t_bool at_head, size_t n);
void		stack_push(t_stack *stack, t_node *node);
t_bool		stack_pushv(t_stack *stack, int32_t val, uint32_t target_pos);
t_node		*stack_pop(t_stack *stack);
void		node_swapv(t_node *a, t_node *b);
void		stack_clear(t_stack	*stack);
void		stack_rrotate(t_stack *stack);
void		stack_rotate(t_stack *stack);

t_bool		pa(t_stack *a, t_stack *b);
t_bool		pb(t_stack *a, t_stack *b);
t_bool		px(t_stack *from, t_stack *to);
void		px_n(t_stack *from, t_stack *to, size_t n);

t_bool		sx(t_stack *s);
t_bool		sa(t_stack *a);
t_bool		sb(t_stack *b);
t_bool		ss(t_stack *s1, t_stack *s2);

t_bool		ra(t_stack *a);
t_bool		rb(t_stack *b);
t_bool		rx(t_stack *s);
t_bool		rr(t_stack *s1, t_stack *s2);

t_bool		rra(t_stack *a);
t_bool		rrb(t_stack *b);
t_bool		rrx(t_stack *s);
void		rrx_n(t_stack *s, size_t n);
t_bool		rrr(t_stack *s1, t_stack *s2);
void		rrr_n(t_stack *s1, t_stack *s2, size_t n);

void		print_sort_op(t_sort_op op);
const char	*sort_op_str(t_sort_op op);

#endif
