CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/ 
FILES = edges ft graph list main stack dfs
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
