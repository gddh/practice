CC = gcc

CFLAGS = -Wall -Werror -Wextra

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
	/bin/rm test $(OBJS)

re : fclean all
