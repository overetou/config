#include "libft.h"

//Returns true if the char is a digit, false if not.
BOOL	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

BOOL	is_lowercase(char c)
{
	return ('a' <= c && c <= 'z');
}

BOOL	is_uppercase(char c)
{
	return ('A' <= c && c <= 'Z');
}

BOOL	is_alpha(char c)
{
	return (is_lowercase(c) || is_uppercase(c));
}

BOOL	is_alphanum(char c)
{
	return (is_digit(c) || is_alpha(c));
}
