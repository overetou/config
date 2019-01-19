#include "libshuttle.h"

//Says if two tabs are equal on their <size> first number.
BOOL	cmp_tab(const int* tab1, const int* tab2, const int size)
{
	int	i = 0;

	while (i != size)
	{
		if (tab1[i] != tab2[i])
			return (0);
		i++;
	}
	return (1);
}
