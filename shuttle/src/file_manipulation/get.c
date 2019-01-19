#include "libshuttle.h"

//reads a char from a file and return it. The cast is here because fgetc extracts ascii values as int and we want our char to be nively typed.
//Note that the file reading cursor progresses automatically when reading with this system calls. So no incrementation needed here.
//This is a poorly efficient way of reading.
char    get_char(int file_descriptor)
{
	char	c;

        read(file_descriptor, &c, 1);
	return (c);
}

//Extracts an int from a file. The 'separator' argument is the char that is supposed to appear after the int text in the file. If not -> error, exit.
//While parsing the int, makes sure that : a number is not to big, that chars supposed to be digits are so, that end of file is not reached when not expected and that the expected separat    or is there.
//This func is bulky and not easy to read, there is a fair room for improvement.
int     get_int(int raw_file, LI* to_travel, char separator)
{
        char    buff[INT_MAX_LENGTH];
        int     i = 0;
        int     extracted_int;
        
        buff[0] = get_char(raw_file);
        (*to_travel)--;
        if (!is_digit(buff[0]) || !(*to_travel))
                exit_msg ("Found something else than a digit when not supposed to, or further reading impossible when it should have been.");
        while ((buff[++i] = get_char(raw_file)) != separator)
        {
                (*to_travel)--;
                if (!(*to_travel))
                        exit_msg("no file content left while expecting int");
                else if(!is_digit(buff[i]))
                        exit_msg("Found something else than a digit when not supposed to.");
                else if (i > INT_MAX_LENGTH)
                        exit_msg("One number is to big to fit in.");
        }
        (*to_travel)--;
        extracted_int = str_to_int(buff);
        if ((i == INT_MAX_LENGTH && extracted_int < 0))
                exit_msg("Too big number for int");
        return (extracted_int);
}

//get the next word in a file.
char	get_word(int file, char* to_fill, SIZE word_max_length)
{
	int	i = 0;
	char	c;

	while(is_alphanum(c = get_char(file)) && i != word_max_length)
	{
		to_fill[i] = c;
		i++;
	}
	return (c);
}

//fills a buffer with the next code line.
void	get_code_line(int file, char*  prototype_buffer)
{
	while((*prototype_buffer = get_char(file)) != '\n')
		prototype_buffer++;
	*prototype_buffer = '\0';
}
