#include "libft.h"

int	count_char(const char* str, char to_find)
{
	int	count = 0;
	int	i = 0;

	while (str[i])
	{
		if (str[i] == to_find)
			count++;
		i++;
	}
	return (count);
}
