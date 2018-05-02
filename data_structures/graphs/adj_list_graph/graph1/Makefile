CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = test
OBJS = ft.o graph.o help_lst.o lst.o main.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.PHONY : all clean fclean re

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(TARGET)

re : fclean all
