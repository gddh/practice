CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = ft.o helper_stack.o stack.o test.o

TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o test $(OBJS)

$(OBJS) : stack.h


.PHONY : clean fclea ren

clean :
	/bin/rm $(OBJS)

fclean :
	/bin/rm test $(OBJS)

re : fclean all
