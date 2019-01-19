#include "libshuttle.h"

BOOL	find_prototype_in_file(int file, char* prototype_buffer)
{
	string(left_word, 5)
	C_TYPES

	//problem : loop does not stop when end of file is reached.
	while (get_word(file, left_word, 5) != EOF)
	{
		putendl("get_word launched.");
		if(str_equals_any(left_word, c_types))
		{
			//copy string returns the length of what was copied.
			get_code_line(file, prototype_buffer + copy_string(left_word, prototype_buffer));
			return (1);
		}
		else
			go_next_line(file);
	}
	return (0);
}
