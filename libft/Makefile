NAME = libshuttle.a

SRC = $(shell find src/ -type f -regex ".*\.c")

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, re

all:
	$(CC) -c $(SRC) -I includes/
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

clean_all: clean
	rm libshuttle.a

re: clean_all all
