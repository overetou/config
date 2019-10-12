/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:11:12 by overetou          #+#    #+#             */
/*   Updated: 2019/06/27 19:21:03 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

UINT	str_get_uint_size(const char *str)
{
	UINT	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int		str_get_int(const char *str, UINT nb_size)
{
	int		nb;
	UINT	i;

	i = 1;
	nb = str[0] - '0';
	while (i != nb_size)
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb);
}

int		str_get_signed_int(const char *str, UINT nb_size)
{
	if (str[0] == '-')
		return (-str_get_int(str + 1, nb_size - 1));
	else if (str[0] == '+')
		return (str_get_int(str + 1, nb_size - 1));
	return (str_get_int(str, nb_size));
}

int		str_get_int_with_sign(const char *str, UINT nb_size, int sign)
{
	if (sign < 0)
		return (-str_get_int(str, nb_size));
	return (str_get_int(str, nb_size));
}
