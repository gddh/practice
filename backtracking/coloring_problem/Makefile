CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = coloring.o ft.o main.o
INC = coloring.h
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
