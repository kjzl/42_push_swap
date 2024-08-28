NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -O3 -flto
# CFLAGS = -Wall -Wextra -Werror -g -Og

LIBFTDIR = libft

SRCS = \
	main.c\
	sort.c\
	sort2.c\
	sort3.c\
	chunk.c\
	stack/stack.c\
	stack/stack_at.c\
	stack/stack_clear.c\
	stack/stack_push_pop.c\
	stack/stack_rotate.c\
	stack/stack_parse.c\
	stack/stack_new.c\
	stack/ops/op_convert.c\
	stack/ops/op_push.c\
	stack/ops/op_rotate.c\
	stack/ops/op_swap.c\
	stack/ops/op_rrotate.c\

OBJ = $(SRCS:.c=.o)

%.o: %.c
	cc $(CFLAGS) -c -I$(LIBFTDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR) CFLAGS='$(CFLAGS)'
	cc $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lft -o $(NAME)

# bonus: CFLAGS += -DBONUS
# bonus: all

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
