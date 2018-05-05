CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/
FILES = print graph edge list main queue bfs jfj
OBJS = $(addprefix srcs/, $(addsuffix .o, $(FILES)))
NAME = test

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.PHONY : all clean fclean re

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all
