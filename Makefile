# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:17:40 by merlich           #+#    #+#              #
#    Updated: 2022/02/24 22:31:27 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	main.c ft_split.c ft_strlen.c ft_strtrim.c ft_substr.c \
			characters.c ft_num_len.c ft_printf.c numbers.c \
			ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_strjoin.c list_functions.c ft_strncmp.c \
			ft_strdup.c stdin_parser.c \
			error.c close_fd.c childs.c \

OBJS_DIR =	objs/

OBJS	=	${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}

HEADER	=	pipex.h

# D_FILES	=	${OBJS:.o=.d}

CLANG	=	clang

CFLAGS	=	-Wall -Wextra -I ${HEADER}

RM		=	rm -rf

${OBJS_DIR}%.o:	%.c
				mkdir -p ${OBJS_DIR}
				${CLANG} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: 	${OBJS}
		${CLANG} ${OBJS} -o ${NAME}

# -include ${D_FILES}

clean:
		${RM} ${OBJS_DIR}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
