#include "libft.h"

//returns the size of the number string. Puts the number string as int in the tab at spot 'count'.
int	get_number(const char* str, int* tab, const char separator)
{
	char	buff[INT_MAX_LENGTH];
	int	i = 1;

	buff[0] = str[0];
        if (!is_digit(buff[0]))
		exit_arrow(str, 0, "No digit at :");
	while(str[i] != separator)
	{
		if (i > INT_MAX_LENGTH || !is_digit(str[i]))
			exit_arrow(str, i, "Entry error  at :");
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	*tab = str_to_int(buff);
	return (i + 1);
}

//This func returns an int wich tells the number of int following. Those are the numbers inputed by the user. If error of entry, returns NULL.
int*	input_numbers(const char* str, int* tab_size_tofill)
{
	int	i;
	int	count;
	//tab[0] = number of folowing number.
	int*	tab;

	*tab_size_tofill = count_char(str, ',');
	tab = (int*)malloc(sizeof(int) * ((*tab_size_tofill) + 1));
	i = 0;
	count = 0;
	while (count != *tab_size_tofill)
	{
		i += get_number(str + i, tab + count, ',');
		count++;
		if (!str[i])
			return (tab);
//		i++;
	}
	get_number(str + i, tab + count, '\0');
	(*tab_size_tofill)++;
	return (tab);
}
