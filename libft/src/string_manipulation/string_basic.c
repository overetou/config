#include <stdlib.h>

int	slen(char* str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char*	strnew(const char* str, int length)
{
	return ((char*)malloc(sizeof(char) * length));
}

int	copy_string(const char* source, char* recipient)
{
	int i = 0;

	while(source[i])
	{
		recipient[i] = source[i];
		i++;
	}
	return (i);
}
	
