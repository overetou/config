/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_put_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:16:03 by overetou          #+#    #+#             */
/*   Updated: 2019/03/18 18:13:49 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_nb(UINT n, const UINT nb_size)
{
	char	buf[nb_size];
	UINT	i;

	i = nb_size;
	while (i)
	{
		i--;
		buf[i] = (char)(n % 10 + '0');
		n /= 10;
	}
	dry_put_str(buf, nb_size);
}

void	put_decimal(float f)
{
	char	buf[7];
	UINT	i;

	if (no_remaining_decimal(f, 1))
		return ;
	buf[0] = '.';
	i = 1;
	while (i != 7)
	{
		f *= 10;
		buf[i] = (char)f + '0';
		f -= (char)f;
		i++;
		if (no_remaining_decimal(f, i))
			break ;
	}
	dry_put_str(buf, i);
}

void	put_float(float f)
{
	put_nb((UINT)f, find_nb_length((UINT)f));
	put_decimal(f - (UINT)f);
}

void	put_signed_float(float f)
{
	if (f < 0)
	{
		put_char('-');
		put_float(-f);
	}
	else
		put_float(f);
}

void	put_operation_float(float f)
{
	if (f < 0)
	{
		put_str("- ");
		put_float(-f);
		return ;
	}
	put_str("+ ");
	put_float(f);
}
