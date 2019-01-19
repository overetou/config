#include "libshuttle.h"

void	putchr(const char c)
{
	write(1, &c, 1);
}

void	putstr(const char* str)
{
	write(1, str, slen(str));
}

void	putendl(const char* str)
{
	write(1, str, slen(str));
	write(1, "\n", 1);
}

void	put_arrow(const char* str, int i)
{
	putendl(str);
	while (i--)
		putchr(' ');
	putendl("^\n");
}

void	putnb(const int n, const  mult_size_t meta)
{
	char	buff[meta.size + 1];

	int_to_str(n, buff, meta.mult);
	putstr(buff);
}

void	quick_putnb(const int n)
{
	mult_size_t	meta;

	find_mult_size(n, &meta);
	putnb(n, meta);
}

void	puttab(const int* tab, int size)
{
	int		i = 0;
	mult_size_t	meta;

	size--;
	while (i != size)
	{
		find_mult_size(tab[i], &meta);
		putnb(tab[i], meta);
		i++;
		putstr(", ");
	}
	find_mult_size(tab[i], &meta);
	putnb(tab[i], meta);
}
