SRCS = main.c ./parsing/parsing_utils.c ./moves/swap.c ./moves/rotate.c ./moves/r_rotate.c ./moves/push.c ./moves/ss.c ./moves/rr.c ./moves/rrr.c ./sorting/chunk_sort.c ./sorting/sort_three.c ./sorting/sortarr.c ./sorting/sort_small.c ./sorting/chunk_utils.c
BONUS_SRCS = ./bonus/parsing_bonus.c ./bonus/utils_bonus.c ./moves/swap.c ./moves/rotate.c ./moves/r_rotate.c ./moves/push.c ./moves/ss.c ./moves/rr.c ./moves/rrr.c ./bonus/checker_bonus.c ./bonus/gnl/get_next_line.c ./bonus/gnl/get_next_line_utils.c ./bonus/append_bonus.c ./bonus/clear_bonus.c ./bonus/delmove_bonus.c ./bonus/new_bonus.c ./bonus/last_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_HEADERS = ./bonus/checker_bonus.h
INCLUDES = ./includes
HEADERS = $(INCLUDES)/parsing.h $(INCLUDES)/moves.h ./sorting/chunks_local.h
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
LIBFTDIR = ./libft
LIBFT	= $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cc $(OBJS) -I$(INCLUDES) -L$(LIBFTDIR) -lft -o $(NAME)

$(OBJS): $(HEADERS)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	cc $(BONUS_OBJS) -I$(INCLUDES) -L$(LIBFTDIR) -lft -o $(BONUS_NAME)

%.o: %.c
	cc $(CFLAGS) -I$(INCLUDES) -c $< -o $@

bonus/%.o: bonus/%.c $(BONUS_HEADERS)
	cc $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(LIBFT): $(LIBFTHEADER)
	make bonus -C $(LIBFTDIR)

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
