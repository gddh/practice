CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/
ODIR = objs/
SDIR = srcs/
NAME = test
FILES = main ft stack trap helper jfj
OBJS = $(addprefix objs/, $(addsuffix .o, $(FILES)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(ODIR)%.o : $(SDIR)%.c | $(ODIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(ODIR) :
	mkdir -p $@

.PHONY : all clean fclean re

clean :
	rm -f $(OBJS)
	rm -rf $(ODIR)

fclean :
	rm -f $(OBJS) $(NAME)
	rm -rf $(ODIR)

re : fclean all
