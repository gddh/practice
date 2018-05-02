CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = heap.o ft.o helper_heap.o main.o

TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS) : heap.h

.PHONY : clean fclean re

clean :
	/bin/rm $(OBJS)

fclean :
	/bin/rm $(OBJS) $(TARGET)

re : fclean all
