#include "libshuttle.h"

//Tells if the strings are matched. If so, give string length. If not, send 0.
int	strings_match(const char* str1, const char *str2)
{
	int	i = 0;
	while(str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (!str1[i] && !str2[i])
		return (1);
	return (0);
}

//Returns true if one candidate string matches the other.
BOOL	str_equals_any(char* str, char** candidates)
{
	while(*candidates)
	{
		putstr("Comparing : '");
		putstr(str);
		putstr("' and : '");
		putendl(*candidates);
		if(strings_match(str, *candidates))
		{
			putendl("They are the same.");
			return (1);
		}
		candidates++;
		putendl("They are not the same.");
	}
	return (0);
}
