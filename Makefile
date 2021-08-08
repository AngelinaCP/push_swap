PUSH_SWAP = push_swap
CHECKER = checker
CFLAGS  = -Wall -Wextra -Werror

CC   = gcc

HEADER  = push_swap.h

LIBFT = ./libft/libft.a

RM   = rm -f

SRCS	=	push_swap.c commands.c mini_sort.c operations.c  check.c utils.c find_max_min.c find_mark.c check_2.c mini_sort_5.c push_a_b.c utils_2.c

SRCS_B  =   checker.c gnl/get_next_line.c utils.c commands.c mini_sort.c operations.c  check.c find_max_min.c find_mark.c check_2.c mini_sort_5.c push_a_b.c utils_2.c

OBJS   = ${SRCS:.c=.o}

OBJS_B   = ${SRCS_B:.c=.o}

all:   ${PUSH_SWAP}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(PUSH_SWAP):  $(OBJS)  $(HEADER)
				$(MAKE) -C ./libft
				$(CC) $(OBJS) $(CFLAGS) libft/libft.a   -o $(PUSH_SWAP)

$(CHECKER) :	$(OBJS_B)
				$(CC) $(OBJS_B) $(CFLAGS) libft/libft.a -o $(CHECKER)

bonus:  ${PUSH_SWAP} ${CHECKER}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean:  clean
		${RM} ${PUSH_SWAP} ${CHECKER}

re:   fclean all

.PHONY:  all clean fclean re
