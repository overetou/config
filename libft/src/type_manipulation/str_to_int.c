/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:32:42 by overetou          #+#    #+#             */
/*   Updated: 2019/10/18 18:33:20 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//convert a char to an int. If the char is not a digit, who knows what happens.
int	char_to_int(const char c)
{
	return ((int)(c - 48));
}

//this func should transform an string into an int no matter what. If an unwanted char is encountered, 0 will be returned. If the number is way to large, nothing will be done to prevent the func from messing up.
int	str_to_int(const char* str)
{
	int	to_return = 0;
	int	i = 0;

	while (str[i])
	{
		if (is_digit(str[i]))
		{
			to_return *= 10;
			to_return += char_to_int(str[i]);
		}
		else
			return (0);
		i++;
	}
	return (to_return);
}

//Same as before, but a sign is  allowed, at the price of performance decrease.
int	str_to_int_sign(const char* str)
{
	if (str[0] == '-')
		return (-str_to_int(str + 1));
	else if (str[0] == '+')
		return (str_to_int(str + 1));
	return (str_to_int(str));
}
