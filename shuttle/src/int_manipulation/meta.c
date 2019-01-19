#include "libshuttle.h"

void	find_mult_size(const int n, mult_size_t *to_fill)
{
	to_fill->mult = 1;
	to_fill->size = 1;

	while (n / (to_fill->mult) > 9)
	{
		to_fill->mult *= 10;
		to_fill->size++;
	}
}
