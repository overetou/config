/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:28:15 by overetou          #+#    #+#             */
/*   Updated: 2019/11/18 21:23:42 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

//Expects that n points on 1 or -1 and that buf is positionned on the first digit
//of the number. Returns 0 on overflow and 1 on success.
char	read_int(t_buf *b, int *n)
{
	int	mem;

	mem = *n * char_to_int(b->str[b->pos]);
	////printf("read_int: first mem = %d\n", mem);
	*n = mem;
	if (mem < 0)
	{
		while (read_smart_inc(b) && is_digit(b->str[b->pos]))
		{
			mem = mem * 10 - char_to_int(b->str[b->pos]);
		//	//printf("read_int: step mem = %d\n", mem);
			if (int_have_different_sign(*n, mem))
				return (0);
			*n = mem;
		}
	}
	else
	{
		while (read_smart_inc(b) && is_digit(b->str[b->pos]))
		{
			mem = mem * 10 + char_to_int(b->str[b->pos]);
			if (int_have_different_sign(*n, mem))
				return (0);
			*n = mem;
		}
	}
	return (1);
}

void	read_float_tail(t_buf *b, float *n, float multiplier)
{
	*n = *n + char_to_float(b->str[b->pos]) * multiplier;
	while (read_smart_inc(b) && is_digit(b->str[b->pos]))
	{
		multiplier /= 10;
		*n = *n + char_to_float(b->str[b->pos]) * multiplier;
	}
}

char	read_float(t_buf *b, float *n)
{
	float	mem;
	float	sign;

	sign = *n;
	mem = sign * char_to_int(b->str[b->pos]);
	*n = mem;
	while (read_smart_inc(b))
	{
		if (is_digit(b->str[b->pos]))
		{
			mem = mem * 10 + sign * char_to_float(b->str[b->pos]);
			if (int_have_different_sign(*n, mem))
				return (0);
			*n = mem;
		}
		else if (b->str[b->pos] == '.')
		{
			if (!read_smart_inc(b))
				return (0);
			if (!is_digit(b->str[b->pos]))
				return (0);
			read_float_tail(b, n, sign / 10);
			return (1);
		}
		else
			return(1);
	}
	return (1);
}
