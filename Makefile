NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

PUSH_SWAP_MAIN = push_swap.c

CHECKER_MAIN = checker.c

STACK_UTILS = bench_mode.c bubble_sort.c chunk_sort.c flag_utils.c is_valid.c radix_sort.c stack_utils.c \
				radix_sort_utils.c sort_short.c sorter.c stack_utils2.c max_min.c

STACK_UTILS_OBJS = $(STACK_UTILS:.c=.o)

CHECKER_UTILS = flag_utils.c is_valid.c stack_utils.c stack_utils2.c \
				sort_short.c max_min.c 

CHECKER_UTILS_OBJS = $(CHECKER_UTILS:.c=.o)

OPERATIONS = operation_push.c operation_rotate.c operation_r_rotate.c operation_swap.c

OPERATIONS_BONUS = operation_push_bonus.c operation_rotate_bonus.c operation_r_rotate_bonus.c operation_swap_bonus.c

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

PRINTF = ft_printf/ft_printf.c ft_printf/ft_printf_utils.c

MAIN_OBJS = $(PUSH_SWAP_MAIN:.c=.o) $(STACK_UTILS_OBJS) $(OPERATIONS:.c=.o)

CHECKER_OBJS = $(CHECKER_MAIN:.c=.o) $(CHECKER_UTILS_OBJS) $(OPERATIONS_BONUS:.c=.o)

GNL_OBJS = $(GNL:.c=.o)

PRINTF_OBJS = $(PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(MAIN_OBJS) $(PRINTF_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MAIN_OBJS) $(PRINTF_OBJS) $(LIBFT) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(LIBFT) -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f *.o
	make -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f $(NAME) checker
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re