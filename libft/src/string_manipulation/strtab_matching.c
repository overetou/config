/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:20:20 by overetou          #+#    #+#             */
/*   Updated: 2019/10/22 19:04:23 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		chr_match_any_in_string(const char c, const char *array)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (array[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
//
//int		chr_match_in_any_string(const char c, const char **array_set)
//{
//	int i;
//
//	i = 0;
//	while (array_set[i])
//	{
//		if (chr_match_any_in_array(c, array_set[i]) >= 0)
//			return (i);
//		i++;
//	}
//	return (-1);
//}
