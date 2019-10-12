/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:07:47 by overetou          #+#    #+#             */
/*   Updated: 2019/04/02 14:51:58 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	no_remaining_decimal(float f, UINT i)
{
	while (i != 7)
	{
		if ((f *= 10) >= 1)
			return (0);
		i++;
	}
	return (1);
}

BOOL	float_ad_excess(const float first, const float second)
{
	if (first > 0 && second > 0)
		return (first + second < 0);
	if (first < 0 && second < 0)
		return (first - second > 0);
	return (0);
}

float	float_abs(float f)
{
	return (f < 0 ? -f : f);
}

BOOL	float_equ(float f1, float f2)
{
	return (f1 - f2 < 0.000001 && f1 - f2 > -0.000001);
}
