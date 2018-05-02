CC = gcc

CFLAGS = -Wall -Wextra -Werror

TARGET = test

OBJS = helper.o queue.o sliding_window.o main.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS) : sliding_window.h

.PHONY : clean fclean re

clean :
	/bin/rm $(OBJS)

fclean :
	/bin/rm $(TARGET) $(OBJS)

re :
	fclean all
