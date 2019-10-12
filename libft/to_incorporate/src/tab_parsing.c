/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:20:20 by overetou          #+#    #+#             */
/*   Updated: 2019/07/03 20:42:17 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

UINT	tab_find_first_cor_or_null(UINT to_find, UINT *tab)
{
	UINT i;

	i = 0;
	while (tab[i] && tab[i] != to_find)
		i++;
	return (i);
}

int		chr_match_any_in_array(const char c, const char *array)
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

int		chr_match_any_array(const char c, const char **array_set)
{
	int i;

	i = 0;
	while (array_set[i])
	{
		if (chr_match_any_in_array(c, array_set[i]) >= 0)
			return (i);
		i++;
	}
	return (-1);
}
