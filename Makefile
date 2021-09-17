# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh		#for systems where SHELL variable can be inherited from environment

.SUFFIXES:			#no suffix rules are used

LIBS=				libft/libft.a \

LIBS_EXT=			-lreadline \
					-L/Users/cjettie/.brew/Cellar/readline/8.1/lib/ \

LIBS_DIR=			${dir ${LIBS}}

LIBS_INC_F=			-L ${dir ${LIBS}} -l${patsubst lib%.a, %, ${notdir ${LIBS}}}

LIBS_INC=			${foreach LIBS, ${LIBS}, ${LIBS_INC_F}}

LIBS_HEADERS=		${patsubst %.a, %.h, ${LIBS}}

HEADERS_MINISHELL=	headers/minishell.h

HEADERS_MINISHELL_B=headers/minishell_bonus.h

HEADERS=			${LIBS_HEADERS} ${HEADERS_MINISHELL}

ifdef COMPILE_BONUS
HEADERS:=			${HEADERS} ${HEADERS_MINISHELL_B}
endif

INC_HEADERS_FORMAT=	-I ${dir ${HEADERS}} -I/Users/cjettie/.brew/Cellar/readline/8.1/include

INC_HEADERS_DIR=	${foreach HEADERS, ${HEADERS}, ${INC_HEADERS_FORMAT}}

SRCS_C=				src/minishell.c \
					src/minishell_call.c \
					src/minishell_parser.c \
					src/srt_array_utils.c \
					src/ft_export.c \
					src/ft_export_print.c \
					src/ft_export_add_var.c \
					src/ft_env.c \
					src/ft_unset.c \
					src/ft_pwd.c \
					src/ft_echo.c \
					src/ft_cd.c \
					src/ft_exit.c \
					src/ft_exit_atoi.c \
					src/minishell_parser_command_count.c \
					src/minishell_parser_command_full.c \
					src/minishell_parser_env.c \
					src/minishell_exec_heredoc.c \
					src/minishell_parser_ret_val.c \
					src/minishell_parser_check.c \
					src/minishell_parser_check_position.c \
					src/minishell_exec.c \
					src/minishell_exec_child.c \
					src/minishell_exec_pipe.c \
					src/minishell_exec_redirect.c \
					src/minishell_error.c \
					src/minishell_exit_malloc.c \
					src/minishell_prompt.c \
					src/minishell_parser_word_len.c \
					src/minishell_parser_wildcard.c \
					src/minishell_parser_wildcard_amnt.c \
					src/minishell_get_file_list.c \
					src/minishell_parser_wildcard_write.c \
					src/minishell_signals.c \
					src/minishell_signals_holders.c \
					src/minishell_shlvl.c \

SRCS_C_BONUS=

ifdef COMPILE_BONUS
SRCS_C:=			${SRCS_C} ${SRCS_C_BONUS}
endif

OBJS_S_BONUS=		${SRCS_C_BONUS:.s=.o}

OBJS_C=				${SRCS_C:.c=.o}

NAME=				minishell

CC=					cc
RM=					rm -f
LD=					ld

ALL_CFLAGS=			-Wall -Wextra -Werror -g ${INC_HEADERDIR} ${CFLAGS}
ALL_LDFLAGS=		-g ${LDFLAGS}

NORM=				norminette ${NORMO}

.PHONY:				all clean fclean re bonus libs_make libs_clean

all:				libs_make ${NAME}

libs_make:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} bonus}

%.o:				%.c ${HEADERS}
					${CC} ${ALL_CFLAGS} ${INC_HEADERS_DIR} -c ${<} -o ${<:%.c=%.o}

${NAME}:			${OBJS_C} ${LIBS}
					${CC} ${ALL_LDFLAGS} ${OBJS_C} ${LIBS_INC} ${LIBS_EXT} -o ${NAME}

bonus:
					${MAKE} COMPILE_BONUS=1 all

#$(INSTALL_PROGRAM)=	${TEST_NAME} $(DESTDIR)$(bindir)/foo	#where executeable shoud be placed
#$(INSTALL_DATA)=	${NAME} $(DESTDIR)$(libdir)/libfoo.a		#where libs shoud be placed



clean:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} clean}
					${RM} ${OBJS_C} ${OBJS_C_BONUS}

fclean:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} fclean}
					${RM} ${OBJS_C} ${OBJS_C_BONUS}
					${RM} ${NAME}

norm:		
					${NORM} ${LIBS_DIR} *.c *.h

re:					fclean all

# .DELETE_ON_ERROR