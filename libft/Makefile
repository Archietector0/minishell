# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:46:25 by cjettie           #+#    #+#              #
#    Updated: 2020/11/16 17:00:42 by cjettie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBHEADER		= libft.h

LIBC			= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				  ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				  ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_strcmp.c

ADDITFUNCT		= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				  ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				  ft_putnbr_fd.c ft_num_amount.c

BONUS			= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

TURNINHEADER	= ${LIBHEADER}

TURNINCODE		= ${LIBC} ${ADDITFUNCT} ${BONUS}

HEAD			= ${TURNINHEADER}

TURNIN			= ${TURNINHEADER} ${TURNINCODE}

SRCS			= ${LIBC} ${ADDITFUNCT}

SRCS_B			= ${LIBC} ${ADDITFUNCT} ${BONUS}

NORMO			= ${TURNIN}

OBJS			= ${SRCS:.c=.o}

OBJS_B			= ${SRCS_B:.c=.o}

NAME			= libft.a

CC				= cc
RM				= rm -f
AR				= ar -crs

CFLAGS			= -Wall -Wextra -Werror -g

NORM			= norminette

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:			${NAME}

ifndef COMPILE_BONUS
${NAME}:		${OBJS} ${LIBHEADER}
				${AR} ${NAME} ${OBJS}
else
${NAME}:		${OBJS_B} ${LIBHEADER}
				${AR} ${NAME} ${OBJS}
endif

clean:
				${RM} ${OBJS_B}

fclean:			clean
				${RM} ${NAME}

norm:		
				${NORM} ${NORMO}

re:				fclean ${NAME}

bonus:
				${MAKE} COMPILE_BONUS=1 all

.PHONY:			all clean fclean re bonus
