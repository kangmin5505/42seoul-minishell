# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 20:38:43 by kangkim           #+#    #+#              #
#    Updated: 2022/02/10 11:38:19 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
_END	=	\033[0;0m
_GREEN	=	\033[0;32m

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = srcs
SRCS2_DIR = srcs2-1
SHELL_DIR = $(SRCS_DIR)/shell
EXECUTER_DIR = $(SRCS_DIR)/executer
ENVS_DIR = $(SRCS_DIR)/envs
UTILS_DIR = $(SRCS_DIR)/utils
COMMANDS_DIR = $(SRCS_DIR)/commands
REDIRECTIONS_DIR = $(SRCS_DIR)/redirections
INCLUDE_DIR = includes

SHELL_SRCS = set_shell.c read_shell.c set_shell_tcattr.c
SHELL_SRCS := $(addprefix $(SHELL_DIR)/, $(SHELL_SRCS))

EXECUTER_SRCS = executer.c executer_utils.c
EXECUTER_SRCS := $(addprefix $(EXECUTER_DIR)/, $(EXECUTER_SRCS))

ENVS_SRCS = envs.c envs_func.c envs_utils.c envs_utils2.c
ENVS_SRCS := $(addprefix $(ENVS_DIR)/, $(ENVS_SRCS))

UTILS_SRCS = utils.c
UTILS_SRCS := $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

COMMANDS_SRCS = builtin_env.c builtin_exit.c builtin_echo.c builtin_cd.c \
		builtin_pwd.c builtin_unset.c builtin_export.c builtin_export_sub.c
COMMANDS_SRCS := $(addprefix $(COMMANDS_DIR)/, $(COMMANDS_SRCS))

REDIRECTIONS_SRCS = redirections_cmd.c output_redirections.c input_redirections.c
REDIRECTIONS_SRCS := $(addprefix $(REDIRECTIONS_DIR)/, $(REDIRECTIONS_SRCS))

SRCS = $(SRCS_DIR)/main.c $(SHELL_SRCS) $(EXECUTER_SRCS) $(ENVS_SRCS) \
       $(UTILS_SRCS) $(COMMANDS_SRCS) $(REDIRECTIONS_SRCS)
OBJS = $(SRCS:.c=.o)

SRCS2 = ft_charlist.c ft_interpret.c \
	 ft_strutils.c ft_strutils2.c ft_procedure.c ft_select.c \
	 ft_while.c ft_pipe.c ft_free.c ft_charlist.c ft_process.c \
	 ft_error.c ft_preprocess.c ft_pipeutils.c ft_valueinterpret.c
SRCS2 := $(addprefix $(SRCS2_DIR)/, $(SRCS2))
OBJS2 = $(SRCS2:.c=.o)

LIBFT_DIR = $(SRCS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBREADLINE_DIR = $(SRCS_DIR)/readline
LIBREADLINE = $(LIBREADLINE_DIR)/libreadline.a
LIBHISTORY = $(LIBREADLINE_DIR)/libhistory.a

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS2) $(LIBFT) $(LIBREADLINE) $(LIBHISTORY)
	@echo "$(_GREEN)[ Try to make $(NAME) ]$(_END)"
	@$(CC) $(CFLAGS) -lncurses -o $@ $^
	@echo "$(_GREEN)[ Done ]$(_END)"

%.o : %.c
	@$(CC) -c $(CFLAGS) -I./$(INCLUDE_DIR) -I./$(LIBREADLINE_DIR) -o $@ $<

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR) all

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(OBJS2)

fclean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJS) $(OBJS2)
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
