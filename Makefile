# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 20:38:43 by kangkim           #+#    #+#              #
#    Updated: 2022/01/21 17:38:01 by kangkim          ###   ########.fr        #
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
SHELL_DIR = $(SRCS_DIR)/shell
INCLUDE_DIR = includes

SHELL_SRCS := set_shell.c read_shell.c
SHELL_SRCS := $(addprefix $(SHELL_DIR)/, $(SHELL_SRCS))

SRCS := $(SRCS_DIR)/main.c $(SHELL_SRCS)
OBJS := $(SRCS:.c=.o)

LIBFT_DIR = $(SRCS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBREADLINE_DIR = $(SRCS_DIR)/readline
LIBREADLINE = $(LIBREADLINE_DIR)/libreadline.a
LIBHISTORY = $(LIBREADLINE_DIR)/libhistory.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(LIBREADLINE) $(LIBHISTORY)
	@echo "$(_GREEN)[ Try to make $(NAME) ]$(_END)"
	@$(CC) $(CFLAGS) -lncurses -o $@ $^
	@echo "$(_GREEN)[ Done ]$(_END)"

%.o : %.c
	@$(CC) -c $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBREADLINE_DIR) -o $@ $<

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR) all

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
