/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:01:35 by overetou          #+#    #+#             */
/*   Updated: 2019/03/18 18:02:53 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

UINT	compare_str(const char *str1, const char *str2)
{
	UINT	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (i);
}

BOOL	str_match(const char *str1, const char *str2)
{
	UINT	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

BOOL	str_perfect_match(const char *str1, const char *str2)
{
	return (len_str(str1) == len_str(str2) && str_match(str1, str2));
}

BOOL	str_equals_any(char *str, char **candidates)
{
	while (*candidates)
	{
		if (str_perfect_match(str, *candidates))
			return (1);
		candidates++;
	}
	return (0);
}
