/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:37:37 by overetou          #+#    #+#             */
/*   Updated: 2019/03/28 19:10:03 by overetou         ###   ########.fr       */
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

BOOL	flt_par_digitnb(const float nb)
{
	return (find_float_length(nb) % 2);
}

void	resolve_first_degree(float *v, float *solutions)
{
	*solutions = -*v / v[1];
}

UINT	resolve_second_degree(float *v, float *solutions)
{
	float delta;

	delta = v[1] * v[1] - 4 * v[2] * *v;
	if (delta < 0)
	{
		putstr("Discriminant is strictly negative, solutions are:\n");
		*solutions = -v[1] / (2 * v[2]);
		solutions[1] = squrt_2(-delta, flt_par_digitnb(-delta)) / (2 * v[2]);
		return (3);
	}
	if (delta)
	{
		putendl("Discriminant is strictly positive, solutions are:");
		delta = squrt_2(delta, find_float_length(delta) % 2);
		*solutions = (-v[1] - delta) / (2 * v[2]);
		solutions[1] = (-v[1] + delta) / (2 * v[2]);
		return (2);
	}
	*solutions = -v[1] / (2 * v[2]);
	putstr("Discriminant is null. ");
	return (1);
}

int		do_resolution(float *v, unsigned int size, float *solutions)
{
	putstr("Polynomial degree : ");
	quick_putnb(size < 2 ? 0 : size - 1);
	putstr(".\n");
	if (size == 0)
		return (0);
	else if (size == 1)
		return (-1);
	else if (size == 2)
	{
		resolve_first_degree(v, solutions);
		return (1);
	}
	return (resolve_second_degree(v, solutions));
}
