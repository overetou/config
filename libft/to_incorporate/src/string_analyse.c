/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_analyse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:08:02 by overetou          #+#    #+#             */
/*   Updated: 2019/06/18 17:11:54 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

BOOL	is_sign_or_digit(const char c)
{
	return (is_digit(c) || c == '-' || c == '+');
}

BOOL	is_endline(const char c)
{
	return (c == '\n');
}

BOOL	str_int_too_big(const char *str, UINT s, const int nb, const int sign)
{
	if (s == INT_MAX_SIZE)
	{
		if (str[0] > '2')
			return (0);
		if (str[0] == '2')
		{
			if (sign < 0)
			{
				if (nb >= 0)
					return (0);
			}
			else if (nb < 0)
				return (0);
		}
	}
	return (1);
}
