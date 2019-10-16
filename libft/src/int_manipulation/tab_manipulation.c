#include "libft.h"

int	snowball_operation(const int* tab, const int size, int (*operation)(const int, const int))
{
	int	i = 1;
	int	result;

	result = tab[0];
	while(i != size)
	{
		result = operation(result, tab[i]);
		i++;
	}
	return (result);
}

int	sum(const int n1, const int n2)
{
	return (n1 + n2);
}

int	multiply(const int n1, const int n2)
{
	return (n1 * n2);
}

int	divide(const int n1, const int n2)
{
	return (n1 / n2);
}

int	sum_tab(const int* tab, const int size)
{
	return (snowball_operation(tab, size, sum));
}

//Put NULL params if you don't need them.
void	do_for_each(int* tab, int size, void (*operation)(int*, int*), int* params)
{
	int i = 0;

	while (i != size)
	{
		operation(tab + i, params);
		i++;
	}
}
