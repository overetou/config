/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_increment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:58:43 by overetou          #+#    #+#             */
/*   Updated: 2019/07/03 19:16:25 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rect_increment(int *tab, const int col_nb)
{
	if (tab[0] + 1 == col_nb)
	{
		tab[0] = 0;
		tab[1]++;
	}
	else
		tab[0]++;
}

void	dual_incrementation(int *n1, UINT *n2)
{
	(*n1)++;
	(*n2)++;
}
