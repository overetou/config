/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:15:03 by overetou          #+#    #+#             */
/*   Updated: 2019/03/18 17:15:14 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_float_tab(float *tab, float value, UINT length)
{
	while (length--)
		tab[length] = value;
}

void	fill_uint_tab(UINT *tab, UINT value, UINT length)
{
	while (length--)
		tab[length] = value;
}
