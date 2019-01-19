NAME = LaunchTest

SRC =  main.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, re

all:
	$(CC) $(SRC) ../libshuttle.a -I ../includes/
#	$(CC) *.o -o $(NAME)

clean:
	rm -f *.o

re: clean all

sandpool:
	gcc sandPool.c ../libshuttle.a  -I ../includes/

