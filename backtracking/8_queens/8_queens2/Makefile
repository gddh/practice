CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS =  main.o queens.o safe.o board.o help.o
INC = queens.h
TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS) : $(INC)

.PHONY : clean fclean re

clean :
	/bin/rm $(OBJS)

fclean :
	/bin/rm $(OBJS) $(TARGET)

re : fclean all
