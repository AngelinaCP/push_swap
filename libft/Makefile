# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 17:46:16 by ddelena           #+#    #+#              #
#    Updated: 2021/05/12 11:46:49 by ddelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
HEAD	= libft.h
SRCS	=	ft_atoi.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
			ft_isdigit.c	ft_isprint.c	ft_memccpy.c	ft_memchr.c		\
			ft_memcmp.c		ft_memcpy.c		ft_memset.c		ft_strchr.c		\
			ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		ft_strncmp.c	\
			ft_strnstr.c	ft_strrchr.c	ft_tolower.c	ft_toupper.c	\
			ft_bzero.c		ft_memmove.c	ft_calloc.c		ft_strdup.c		\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_substr.c		\
			ft_strmapi.c	ft_strjoin.c	ft_itoa.c		ft_putnbr_fd.c	\
			ft_split.c		ft_strtrim.c									\
			
SRCS_bonus	=	ft_lstnew.c			ft_lstmap.c		ft_lstiter.c			\
			ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c				\
			ft_lstadd_back.c 	ft_lstdelone.c	ft_lstclear.c				\

OBJS	= ${SRCS:.c=.o}

OBJS_bonus	= ${SRCS_bonus:.c=.o} 

%.o : %.c	${HEAD}
		${CC} ${FLAGS} -c $< -o $@

$(NAME): all

all: ${OBJS} ${HEAD}
		ar rcs ${NAME} $?

bonus:	${OBJS} ${OBJS_bonus}
		ar rcs ${NAME} $?

clean:
		rm -f ${OBJS} ${OBJS_bonus}

fclean:	clean
		rm -f ${NAME} 
re:		fclean all

.PHONY:	all, clean, fclean, re