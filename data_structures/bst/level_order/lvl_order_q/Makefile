CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/
ODIR = objs/
SDIR = srcs/
FILES = bfs bst helper main q traversals
OBJS = $(addprefix $(ODIR), $(addsuffix .o, $(FILES)))
NAME = test

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(ODIR)%.o : $(SDIR)%.c | $(ODIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(ODIR) :
	mkdir -p $@

.PHONY : re clean fclean all

clean : 
	rm -rf $(ODIR)

fclean :
	rm -rf $(ODIR) $(TARGET)

re : fclean all
