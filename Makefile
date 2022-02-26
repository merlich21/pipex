# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:17:40 by merlich           #+#    #+#              #
#    Updated: 2022/02/26 21:45:45 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

HEADER_DIR	=	includes/

HEADER_SRCS	=	pipex.h
HEADER_M	=	${addprefix ${HEADER_DIR}, ${HEADER_SRCS}}

HEADER_B_SRCS	=	pipex_bonus.h
HEADER_B		=	${addprefix ${HEADER_DIR}, ${HEADER_B_SRCS}}

SRCM		=	main.c stdin_parser.c error.c close_fd.c childs.c
SRCM_DIR	=	mandatory/
SRCM_PATH	=	${addprefix ${SRCM_DIR}, ${SRCM}}
OBJS_M		=	${SRCM_PATH:.c=.o}

SRCSTR		=	ft_split.c ft_strlen.c ft_strtrim.c ft_substr.c \
				ft_strjoin.c ft_strncmp.c ft_strdup.c
SRCSTR_DIR	=	string_functions/
SRCSTR_PATH	=	${addprefix ${SRCSTR_DIR}, ${SRCSTR}}
OBJS_STR	=	${SRCSTR_PATH:.c=.o}

SRCP		=	ft_printf.c characters.c numbers.c ft_num_len.c \
				ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c
SRCP_DIR	=	ft_printf/
SRCP_PATH	=	${addprefix ${SRCP_DIR}, ${SRCP}}
OBJS_P		=	${SRCP_PATH:.c=.o}

SRCL		=	list_functions.c
SRCL_DIR	=	list_functions/
SRCL_PATH	=	${addprefix ${SRCL_DIR}, ${SRCL}}
OBJS_L		=	${SRCL_PATH:.c=.o}

SRCB		=	main_bonus.c stdin_parser_bonus.c error_bonus.c \
				close_fd_bonus.c childs_bonus.c list_functions_bonus.c
SRCB_DIR	=	bonus/
SRCB_PATH	=	${addprefix ${SRCB_DIR}, ${SRCB}}
OBJS_B		=	${SRCB_PATH:.c=.o}

CLANG	=	clang

CFLAGS	=	-Wall -Wextra  -I ${HEADER_B}

RM		=	rm -rf

%.o:	%.c		${HEADER_B} Makefile
				${CLANG} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS_B} ${OBJS_STR} ${OBJS_P} ${OBJS_L}
			${CLANG} ${OBJS_B} ${OBJS_STR} ${OBJS_P} ${OBJS_L} -o ${NAME}

# bonus:		${OBJS_B} ${OBJS_STR} ${OBJS_P} ${OBJS_L}
# 			@make HEADER_M="${HEADER_B}"
# 			${CLANG} ${OBJS_B} ${OBJS_STR} ${OBJS_P} ${OBJS_L} -o ${NAME}

clean:
		${RM} ${OBJS_M} ${OBJS_B} ${OBJS_STR} ${OBJS_P} ${OBJS_L}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus
