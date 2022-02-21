# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:17:40 by merlich           #+#    #+#              #
#    Updated: 2022/02/21 18:46:35 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	main.c ft_split.c ft_strlen.c ft_strtrim.c ft_substr.c

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
