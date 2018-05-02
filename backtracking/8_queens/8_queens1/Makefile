CC = gcc

CFLAGS = -Wall -Wextra -Wall

OBJS = main.o queens.o helper.o safe.o board.o

TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS) : queens.h


.PHONY : clean fclean re

clean :
	/bin/rm $(OBJS)

fclean : 
	/bin/rm $(OBJS) $(TARGET)

re : fclean all
