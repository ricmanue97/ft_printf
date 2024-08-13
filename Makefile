# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 10:14:13 by ricmanue          #+#    #+#              #
#    Updated: 2024/05/27 15:58:10 by ricmanue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c sources.c sourcesp.c\


CC	=	@cc
CFLAGS	=	-Wall -Werror -Wextra
OBJS	=	${SRCS:.c=.o}
OBJS_B	=	${SRC_B:.c=.o}
RM	=	@rm -f
LIB	=	@ar -rcs

${NAME}: ${OBJS}
	@echo "Created .o files."
	${LIB} ${NAME} ${OBJS}

all: ${NAME}

fclean: clean
	${RM} ${NAME}
	@echo "Cleaned libftprintf.a"

clean:
	${RM} -f ${OBJS}
	@echo "Cleaned .o files."

re: fclean all

.PHONY: all fclean clean re .c.o

