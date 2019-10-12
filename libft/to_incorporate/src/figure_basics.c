/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:59:01 by overetou          #+#    #+#             */
/*   Updated: 2019/06/24 15:57:06 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*tab_coord(int *tab, int x, int y)
{
	*tab = x;
	tab[1] = y;
	return (tab);
}

t_stght	*stght(t_stght *st, int *origin, int *dest)
{
	st->origin = origin;
	st->dest = dest;
	return (st);
}
