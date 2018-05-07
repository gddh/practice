CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/
FILES = bst main traversals
ODIR = objs/
SDIR = srcs/
OBJS = $(addprefix $(ODIR), $(addsuffix .o, $(FILES)))
NAME = test

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(ODIR)%.o : $(SDIR)%.c | $(ODIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(ODIR) :
	mkdir -p $@

.PHONY : all clean fclean re

clean :
	rm -rf $(ODIR)

fclean :
	rm -rf $(ODIR)
	rm $(NAME)

re : fclean all
