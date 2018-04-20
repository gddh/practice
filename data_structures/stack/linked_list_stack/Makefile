CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = helper_stack.o stack.o test.o

TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS) : stack.h

.PHONY : clean fclean re

clean:
	/bin/rm $(OBJS)

fclean:
	/bin/rm $(TARGET) $(OBJS)

re : fclean all
