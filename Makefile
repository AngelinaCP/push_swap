SRCS	=	new_push_swap.c ft_atoi.c ft_isdigit.c ft_strlen.c \
			ft_strncmp.c	ft_split.c commands.c mini_sort.c \
			operations.c  check.c \

HEAD		=		push_swap.h

OBJC    	=       ${SRCS:.c=.o}

NAME		=       push_swap

CC      	=       gcc

FLAGS		=		-Wall -Wextra -Werror

RM			=       rm -rf

%.o:%.c 		$(HEAD)
				$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all:            $(NAME)

$(NAME):        $(OBJC)
				$(CC) $(OBJC)  -o $(NAME)

clean:
				${RM} ${OBJC} ${OBJCB}

fclean:			clean
				${RM} ${NAME} ${NAMEB}

re:				fclean	all

.PHONY:			all clean fclean re bonus
