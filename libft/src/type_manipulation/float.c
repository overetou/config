/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:17:03 by overetou          #+#    #+#             */
/*   Updated: 2019/10/31 15:59:57 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	get_float_tail(float f)
{
	return (f - ((float)((int)f)));
}

BOOL	float_have_different_sign(float n1, float n2)
{
	if (n1 >= 0)
		return (n2 < 0);
	return (n2 >= 0);
}

//Returns 0 in case of overflow.
BOOL	float_simple_power(float *to_power, int power)
{
	float	value;

	if (power < 0)
		return (0);
	if (power == 0)
		*to_power = 1;
	else
	{
		value = *to_power;
		while (power != 1)
		{
			*to_power *= value;
			power--;
		}
	}
	return (1);
}
