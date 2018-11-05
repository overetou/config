CC = clang++
CFLAGS = -Wall -Werror -Wextra
EXEC_NAME = 
SRCS = 
INCLUDES = includes/
#LIBS =
#OBJ_FILES = fichier_1.o fichier_2.o

all : $(EXEC_NAME)

$(EXEC_NAME) 
	$(CC) -o $(EXEC_NAME) $(SRCS)

clean :
	rm $(EXEC_NAME)

re : clean $(EXEC_NAME)
	
