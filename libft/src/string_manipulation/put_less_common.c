/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_less_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:33:32 by overetou          #+#    #+#             */
/*   Updated: 2019/10/30 17:46:25 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	dry_putstr(char *s, int size)
{
	write(1, s, size);
}

void	put_tail(float f)
{
	char	to_put[10];
	int		i;

	f = get_float_tail(f);
	if (f < 0)
		f = -f;
	if (f < 0.0001)
		return ;
	to_put[0] = '.';
	i = 1;
	while (f >= 0.0001 && i < 7)
	{
		f *= 10;
		to_put[i] = float_to_chr(f);
		f -= (float)((int)f);
		i++;
	}
	dry_putstr(to_put, i);
}

void	quick_put_float(float f, BOOL display_minus)
{
	if (display_minus && f < 0 && f > -1)
		putchr('-');
	quick_putnb((int)f, display_minus);
	put_tail(f);
}

void	put_signed_float(float f)
{
	if (f < 0)
	{
		quick_put_float(-f, 1);
	}
	else
	{
		putchr('+');
		quick_put_float(f, 0);
	}
}

void	put_operation_float(float f)
{
	if (f < 0)
	{
		putstr(" - ");
		quick_put_float(-f, 0);
	}
	else
	{
		putstr(" + ");
		quick_put_float(f, 0);
	}
}

