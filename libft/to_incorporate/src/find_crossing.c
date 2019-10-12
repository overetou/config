/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_crossing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:52:05 by overetou          #+#    #+#             */
/*   Updated: 2019/06/18 17:56:56 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_stght_abs_limits(t_stght *s1, t_stght *s2, int *max, int *min)
{
	if (s1->origin[0] > s1->dest[0])
	{
		*max = s1->origin[0];
		*min = s1->dest[0];
	}
	else
	{
		*min = s1->origin[0];
		*max = s1->dest[0];
	}
	if (*max < s2->origin[0])
		*max = s2->origin[0];
	else if (*min > s2->origin[0])
		*min = s2->origin[0];
	if (*max < s2->dest[0])
		*max = s2->dest[0];
	else if (*min > s2->dest[0])
		*min = s2->dest[0];
}

int		*crosspt(t_stght *s1, t_stght *s2, int crosspt[2])
{
	float	e_a[2];
	int		e_b[2];

	e_a[0] = ((float)(s1->dest[1] - s1->origin[1])) /
	((float)(s1->dest[0] - s1->origin[0]));
	e_a[1] = ((float)(s2->dest[1] - s2->origin[1])) /
	((float)(s2->dest[0] - s2->origin[0]));
	e_b[0] = s1->dest[1] - s1->dest[0] * e_a[0];
	e_b[1] = s2->dest[1] - s2->dest[0] * e_a[1];
	crosspt[0] = (e_b[1] - e_b[0]) / (e_a[0] - e_a[1]);
	crosspt[1] = e_a[1] * ((e_b[1] - e_b[0]) / (e_a[0] - e_a[1])) + e_b[1];
	return (crosspt);
}
