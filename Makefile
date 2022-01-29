# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 20:38:43 by kangkim           #+#    #+#              #
#    Updated: 2022/01/28 23:08:17 by kangkim          ###   ########.fr        #
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
SRCS2_DIR = srcs2
SHELL_DIR = $(SRCS_DIR)/shell
EXECUTER_DIR = $(SRCS_DIR)/executer
ENVS_DIR = $(SRCS_DIR)/envs
UTILS_DIR = $(SRCS_DIR)/utils
INCLUDE_DIR = includes

SHELL_SRCS = set_shell.c read_shell.c check_line.c
SHELL_SRCS := $(addprefix $(SHELL_DIR)/, $(SHELL_SRCS))

EXECUTER_SRCS = executer.c pwd.c
EXECUTER_SRCS := $(addprefix $(EXECUTER_DIR)/, $(EXECUTER_SRCS))

ENVS_SRCS = envs.c envs_func.c envs_utils.c
ENVS_SRCS := $(addprefix $(ENVS_DIR)/, $(ENVS_SRCS))

UTILS_SRCS = utils.c
UTILS_SRCS := $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

SRCS = $(SRCS_DIR)/main.c $(SHELL_SRCS) $(EXECUTER_SRCS) $(ENVS_SRCS) \
       $(UTILS_SRCS)
OBJS = $(SRCS:.c=.o)

SRCS2 = ft_charlist.c ft_interpret.c \
	 ft_strutils.c ft_strutils2.c
SRCS2 := $(addprefix $(SRCS2_DIR)/, $(SRCS2))
OBJS2 = $(SRCS2:.c=.o)

LIBFT_DIR = $(SRCS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBREADLINE_DIR = $(SRCS_DIR)/readline
LIBREADLINE = $(LIBREADLINE_DIR)/libreadline.a
LIBHISTORY = $(LIBREADLINE_DIR)/libhistory.a

all : $(NAME)

# CFLAGS 추
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
