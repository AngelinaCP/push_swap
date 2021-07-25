SRCS	=	new_push_swap.c ft_atoi.c ft_isdigit.c ft_strlen.c \
			ft_strncmp.c	ft_split.c

#SRCS_bonus	=	ft_split.c ft_strjoin.c ft_strncmp.c  \
#                main_bonus.c  child_process.c process_exec.c \
#                get_next_line.c get_next_line_utils.c

HEAD		=		push_swap.h

OBJC    	=       ${SRCS:.c=.o}

OBJCB    	=		${SRCS_bonus:.c=.o}

NAME		=       push_swap

#NAMEB		=       pipex_bonus

CC      	=       gcc

FLAGS		=		-Wall -Wextra -Werror

RM			=       rm -rf

%.o:%.c 		$(HEAD)
				$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all:            $(NAME)

$(NAME):        $(OBJC)
				$(CC) $(OBJC)  -o $(NAME)

#bonus:			$(NAMEB)

#$(NAMEB):		$(OBJCB)
#				gcc -c $(SRCS_bonus)
#				$(CC) $(OBJCB) -o $(NAMEB)

clean:
				${RM} ${OBJC} ${OBJCB}

fclean:			clean
				${RM} ${NAME} ${NAMEB}

re:				fclean	all

.PHONY:			all clean fclean re bonus
