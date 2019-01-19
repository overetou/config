#include "libshuttle.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define	C_TYPES char* c_types[] = {"void", "char", "int", "BOOL", "size", NULL};

BOOL	str_equals_any(char* str, char** candidates)
{
	while(*candidates)
	{
		if(strings_match(str, *candidates))
			return (1);
		candidates++;
	}
	return (0);
}

char	get_word(int file, char* to_fill, SIZE word_max_length)
{
	int i = 0;

	while(is_alphanum(to_fill[i] = get_char(file)) && i != word_max_length)
		i++;
	return (to_fill[i]);
}

void	get_code_line(int file, char*  prototype_buffer)
{
	while((*prototype_buffer = get_char(file)) != '\n')
		prototype_buffer++;
	*prototype_buffer = '\0';
}

void	go_next_line(int file)
{
	while (get_char(file) != '\n');
}

BOOL	find_prototype(int file, char* prototype_buffer)
{
	string(left_word, 5)
	C_TYPES

	while (get_word(file, left_word, 5) != EOF)
	{
		putendl("get_word launched.");
		if(str_equals_any(left_word, c_types))
		{
			putendl("Entered the equals any.");
			copy_string(left_word, prototype_buffer);
			get_code_line(file, prototype_buffer);
			return (1);
		}
		else
			go_next_line(file);
	}
	return (0);
}

BOOL	find_string(int file, const char* to_find)
{
	char c;
	int i = 0;

	while ((c = get_char(file)) != EOF)
	{
		if (c == to_find[i])
		{
			i++;
			if (to_find[i] == '\0')
					return (1);
		}
		else
			i = 0;
	}
	return (0);
}

void	close_all(const int* file_descriptors, int file_number)
{
	while(file_number--)
		close(file_descriptors[file_number]);
}

//Not DRY compliant.
void	quick_write_in_file(int file_descriptor, char* str)
{
	write(file_descriptor, str, slen(str));
}

void	add_proto(int file_descriptor, char* prototype_buffer)
{
	lseek(file_descriptor, 0, SEEK_SET);
	while (get_char(file_descriptor) == '#')
		go_next_line(file_descriptor);
	quick_write_in_file(file_descriptor, prototype_buffer);
	write(file_descriptor, ";\n", 2);
}

int	main(void)
{
	//we are trying to take the prototype of the c file and put it in the h file.
	//Step 1 : open the .h file. It will need read and write. //Step 2 : open the .c file. It will need read.
	int	file_descriptors[2];

	file_descriptors[0] = open("prototype.h", O_RDWR);
	file_descriptors[1] = open("prototype_source.c", O_RDONLY);
	//Step 3 : find a prototype in the c file.
	string(prototype_buffer, 81)

	putendl("Before find_prototype.");
	if (find_prototype(file_descriptors[1], prototype_buffer))
		putendl("Prototype found.");
//	//Step 4 : check that it is not present in the .h file.
//	if (!find_string(file_descriptors[0], prototype_buffer))
//	{
//	//Step 5 : add it in the h file if so.
//		add_proto(file_descriptors[0], prototype_buffer)
//	}
//	//Step 6 : Close all files. Generic function
	close_all(file_descriptors, 2);
	return (0);
}
