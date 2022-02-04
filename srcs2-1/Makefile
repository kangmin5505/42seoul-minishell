CC=gcc
FLAG=-Werror -Wextra -Wall
NAME=interpreter
SRCS=ft_strutils.c ft_strutils2.c ft_strutils3.c ft_interpret.c ft_while.c ft_free.c ft_procedure.c ft_select.c ft_error.c ft_charlist.c
OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) main2.c $(FLAGS) $^ -lreadline
$(OBJS): $(SRCS)
	$(CC) -c $(FLAGS) $^
clean:
	rm -rf $(OBJS)
fclean:
	make clean
	rm -rf $(NAME)
re:
	make fclean
	make
