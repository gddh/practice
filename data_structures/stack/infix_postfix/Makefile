CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJS = ft.o helper_stack.o infix_postfix.o stack.o main.o

TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS) : stack.h

.PHONY : clean fclean re

clean :
	/bin/rm $(OBJS)

fclean : 
	/bin/rm $(OBJS) $(TARGET)

re : fclean all
	
