CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = ft.o knights_tour.o main.o board.o 

TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

$(OBJS) : knights_tour.h

.PHONY : clean fclean re

clean :
	/bin/rm $(OBJS)

fclean : clean
	/bin/rm $(TARGET)

re : fclean all
