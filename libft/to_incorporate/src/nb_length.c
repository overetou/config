/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:08:42 by overetou          #+#    #+#             */
/*   Updated: 2019/03/18 18:09:26 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

UINT	find_float_length(float f)
{
	UINT l;

	l = 0;
	while (f >= 10)
	{
		f /= 10;
		l++;
	}
	return (l);
}

UINT	find_nb_length(UINT n)
{
	UINT	l;

	l = 0;
	while (n >= 10)
	{
		l++;
		n /= 10;
	}
	return (l + 1);
}

float	find_divider(float n, float stop)
{
	float	d;

	d = 1;
	while (n / d >= stop)
		d *= 10;
	return (d);
}
