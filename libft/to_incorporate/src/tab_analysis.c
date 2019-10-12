/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:19:03 by overetou          #+#    #+#             */
/*   Updated: 2019/03/18 17:19:21 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	tab_uint_remaining_non_null(const UINT *tab, UINT i, UINT length)
{
	while (i != length)
	{
		if (tab[i])
			return (0);
		i++;
	}
	return (1);
}

BOOL	tab_float_remaining_non_null(const float *tab, UINT i, UINT length)
{
	while (i != length)
	{
		if (tab[i])
			return (1);
		i++;
	}
	return (0);
}
