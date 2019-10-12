/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:06:34 by overetou          #+#    #+#             */
/*   Updated: 2019/06/27 19:20:31 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	string_reverse_find(const char *str, const char to_find, int searchable_s)
{
	while (searchable_s--)
	{
		if (str[searchable_s] == to_find)
			return (searchable_s + 1);
	}
	return (-1);
}
