CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = main.o helper.o maze_solver.o

TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS) : maze_solver.h

.PHONY : clean fclean re

clean : 
	/bin/rm $(OBJS)

fclean : clean
	/bin/rm $(TEST)

re : fclean all
