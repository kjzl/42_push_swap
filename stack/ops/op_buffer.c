#include "stack.h"

/// merge ra,rb / rra,rrb / sa,sb into rr/rrr/ss
static void	ops_optimize(t_vec *ops)
{}

static void	ops_exec(t_vec *ops, t_stack *a, t_stack *b)
{
	size_t		i;
	t_sort_op	*op;

	i = 0;
	op = vec_get(ops);
	while (i < ops->len)
	{
		exec_sort_op(a, b, *op);
		op++;
		i++;
	}
	vec_clear(ops);
}

void	op_buf_mng(t_stack *a, t_stack *b, t_sort_op op, t_bool flush)
{
	static t_vec	op_buf = (t_vec){.len = 0, .heap = 0, .mem_err = 0,
			.element_size = sizeof(t_sort_op)};
	if (flush)
	{
		ops_optimize(&op_buf);
		ops_exec(&op_buf, a, b);
		vec_destroy(&op_buf, 0);
	}
	else
		vec_push(&op_buf, &op);
}

void	op_buf_push(t_stack *a, t_stack *b, t_sort_op op)
{
	op_buf_mng(a, b, op, FALSE);
}

void	op_buf_flush(t_stack *a, t_stack *b)
{
	op_buf_mng(a, b, 0, TRUE);
}
