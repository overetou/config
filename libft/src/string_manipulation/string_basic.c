#include <stdlib.h>

int	slen(char* str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
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
	
char*	strnew(const char* str, int length)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * length + 1);
	if (new)
		copy_string(str, new);
	return (new);
}
