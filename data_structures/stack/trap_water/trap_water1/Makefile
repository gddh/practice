CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I includes/
FILES = ft stack helper trap_rain main
OBJS = $(addprefix srcs/, $(addsuffix .o, $(FILES)))
NAME = trap_rain

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.PHONY : all re clean fclean

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all
