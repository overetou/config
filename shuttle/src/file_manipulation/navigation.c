#include "libshuttle.h"

//This function is currently not used, but is allows the user to cross a serie of identical chars (here we call them 'separators').
//Parsing phylosophy : everything is ok as long as it is awaited.
void	advance_and_check(int raw_file, char to_match, int to_cross, LI* to_travel)
{
	if (to_cross > *to_travel)
		exit_msg("Separators are missing");
	*to_travel -= to_cross;
	while (to_cross)
	{
		if (get_char(raw_file) != to_match)
			exit_msg("Bad file format : unwelcome caractere spotted.");
		to_cross--;
	}
}

//Get down by one line in the file.
void	go_next_line(int file)
{
	char c;

	c = get_char(file);
	while ( c != '\n' && c != EOF)
		c = get_char(file);
}
