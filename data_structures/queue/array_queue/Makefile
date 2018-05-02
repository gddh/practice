CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = queue.o helper_queue.o ft.o main.o

TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) 

$(OBJS) : queue.h 

.PHONY : clean fclean re

clean :
	/bin/rm $(OBJS)

fclean : 
	/bin/rm $(OBJS) $(TARGET)

re :
	fclean all
