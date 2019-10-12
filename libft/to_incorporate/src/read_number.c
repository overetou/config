/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:05:22 by overetou          #+#    #+#             */
/*   Updated: 2019/07/08 15:49:35 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	read_number_digits(t_buf *b, char int_str[INT_MAX_SIZE + 1], UINT *s)
{
	int_str[*s] = b->str[b->pos];
	dual_incrementation(&(b->pos), s);
	if (b->pos == b->length)
	{
		if (!refresh_buf(b))
			return (1);
	}
	while (is_digit(b->str[b->pos]))
	{
		int_str[*s] = b->str[b->pos];
		dual_incrementation(&(b->pos), s);
		if (b->pos == b->length)
		{
			if (!refresh_buf(b))
				break ;
		}
		if (*s == INT_MAX_SIZE)
			return (0);
	}
	return (1);
}

BOOL	read_number(t_buf *b, int *to_fill)
{
	UINT	s;
	int		sign;
	char	int_str[INT_MAX_SIZE + 1];

	s = 0;
	if (b->str[b->pos] < '0')
	{
		sign = (b->str[b->pos] == '-' ? -1 : 1);
		b->pos++;
		if (b->pos == b->length)
			refresh_buf(b);
	}
	else
		sign = 0;
	if (is_digit(b->str[b->pos]) && read_number_digits(b, int_str, &s))
	{
		*to_fill = str_get_int_with_sign(int_str, s, sign);
		return (str_int_too_big(int_str, s, *to_fill, sign));
	}
	return (0);
}

BOOL	read_next_number(t_buf *b, int *to_fill)
{
	if (b->length && read_till_true(b, is_sign_or_digit))
	{
		if (!read_number(b, to_fill))
		{
			put_endl_str("A number presents a problem in the file.");
			return (-1);
		}
		return (1);
	}
	return (0);
}
