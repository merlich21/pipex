# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:17:40 by merlich           #+#    #+#              #
#    Updated: 2022/03/03 20:01:31 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

BONUS	=	bonus

HEADER_M	=	includes/pipex.h
HEADER_B	=	includes/pipex_bonus.h

SRC_M		=	main.c stdin_parser.c error.c close_fd.c childs.c
SRC_M_DIR	=	mandatory/
SRC_M_PATH	=	${addprefix ${SRC_M_DIR}, ${SRC_M}}
OBJS_M		=	${SRC_M_PATH:.c=.o}
D_FILES_M	=	${SRC_M_PATH:.c=.d}

SRC_STR			=	ft_split.c ft_strlen.c ft_strtrim.c ft_substr.c \
				ft_strjoin.c ft_strncmp.c ft_strdup.c
SRC_STR_DIR		=	string_functions/
SRC_STR_PATH	=	${addprefix ${SRC_STR_DIR}, ${SRC_STR}}
OBJS_STR		=	${SRC_STR_PATH:.c=.o}
D_FILES_STR		=	${SRC_STR_PATH:.c=.d}

SRC_P		=	ft_printf.c characters.c numbers.c ft_num_len.c \
				ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c
SRC_P_DIR	=	ft_printf/
SRC_P_PATH	=	${addprefix ${SRC_P_DIR}, ${SRC_P}}
OBJS_P		=	${SRC_P_PATH:.c=.o}
D_FILES_P	=	${SRC_P_PATH:.c=.d}

SRC_L		=	list_functions.c
SRC_L_DIR	=	list_functions/
SRC_L_PATH	=	${addprefix ${SRC_L_DIR}, ${SRC_L}}
OBJS_L		=	${SRC_L_PATH:.c=.o}
D_FILES_L	=	${SRC_L_PATH:.c=.d}

SRC_GNL			=	get_next_line_bonus.c get_next_line_utils_bonus.c 
SRC_GNL_DIR		=	get_next_line/
SRC_GNL_PATH	=	${addprefix ${SRC_GNL_DIR}, ${SRC_GNL}}
OBJS_GNL		=	${SRC_GNL_PATH:.c=.o}
D_FILES_GNL		=	${SRC_GNL_PATH:.c=.d}

SRC_B		=	main_bonus.c error_bonus.c close_fd_bonus.c \
				childs_bonus.c infile_outfile_bonus.c here_doc_bonus.c
SRC_B_DIR	=	bonus/
SRC_B_PATH	=	${addprefix ${SRC_B_DIR}, ${SRC_B}}
OBJS_B		=	${SRC_B_PATH:.c=.o}
D_FILES_B	=	${SRC_B_PATH:.c=.d}

D_FILES		=	${D_FILES_M} ${D_FILES_STR} ${D_FILES_P} \
				${D_FILES_L} ${D_FILES_GNL} ${D_FILES_B}

MANDATORY_O	=	${OBJS_M} ${OBJS_STR} ${OBJS_P} ${OBJS_L}

BONUS_O		=	${OBJS_B} ${OBJS_STR} ${OBJS_P} ${OBJS_GNL}

CLANG	=	clang

CFLAGS	=	-Wall -Wextra -Werror -MD

RM		=	rm -rf

%.o:	%.c
		${CLANG} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${MANDATORY_O}
			${CLANG} ${MANDATORY_O} -o ${NAME}

-include ${D_FILES}

${BONUS}:	${BONUS_O}
			@make MANDATORY_O="${BONUS_O}" all

clean:
		${RM} ${OBJS_M}  
		${RM} ${OBJS_B}
		${RM} ${OBJS_STR}
		${RM} ${OBJS_P}
		${RM} ${OBJS_GNL}
		${RM} ${OBJS_L}
		${RM} ${D_FILES}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus
