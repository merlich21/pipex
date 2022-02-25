# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:17:40 by merlich           #+#    #+#              #
#    Updated: 2022/02/25 20:01:18 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	mandatory/main.c mandatory/stdin_parser.c \
			mandatory/error.c mandatory/close_fd.c mandatory/childs.c \
			string_functions/ft_split.c string_functions/ft_strlen.c \
			string_functions/ft_strtrim.c string_functions/ft_substr.c \
			string_functions/ft_strjoin.c string_functions/ft_strncmp.c \
			string_functions/ft_strdup.c \
			ft_printf/characters.c ft_printf/ft_num_len.c \
			ft_printf/ft_printf.c ft_printf/numbers.c \
			ft_printf/ft_putchar_fd.c ft_printf/ft_putnbr_fd.c \
			ft_printf/ft_putstr_fd.c \
			list_functions/list_functions.c

OBJS_DIR =	

OBJS	=	${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}

HEADER	=	./includes/pipex.h

CLANG	=	clang

CFLAGS	=	-Wall -Wextra -Werror -I ${HEADER}

RM		=	rm -rf

${OBJS_DIR}%.o:	%.c
				@mkdir -p ${OBJS_DIR}
				${CLANG} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: 	${OBJS}
		${CLANG} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS_DIR}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
