/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_float_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:03:17 by overetou          #+#    #+#             */
/*   Updated: 2019/04/19 18:41:08 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	parse_decimals(char *str, UINT nb_size)
{
	float	diviser;
	UINT	i;
	float	result;

	diviser = 10;
	result = 0;
	i = 0;
	while (i != nb_size)
	{
		result += (str[i] - '0') / diviser;
		diviser *= 10;
		i++;
	}
	return (result);
}

float	parse_float(char *str, UINT *float_size)
{
	float			result;
	unsigned short	nb_size;

	nb_size = str_get_uint_size(str);
	if (nb_size && nb_size < 10)
	{
		*float_size = nb_size;
		result = (float)str_get_int(str, nb_size);
		if (str[nb_size] == '.')
		{
			nb_size = str_get_uint_size(str + nb_size + 1);
			if (nb_size && nb_size < 7)
			{
				result += parse_decimals(str + *float_size + 1, nb_size);
				*float_size += 1 + nb_size;
				return (result);
			}
			*float_size = 0;
		}
		return (result);
	}
	return (0);
}
