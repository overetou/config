/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_int_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:00:24 by overetou          #+#    #+#             */
/*   Updated: 2019/06/18 17:00:44 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tab_int_cpy(const int *src, int *targ, USHT length)
{
	while (length--)
		targ[length] = src[length];
}

void	add_int_vectors(int *add1, int *add2, int *result, USHT size)
{
	while (size--)
		result[size] = add1[size] + add2[size];
}

void	tab_int_shift_left(int *tab, const UINT tab_length)
{
	UINT i;

	i = 0;
	while (i != tab_length)
	{
		tab[i] = tab[i + 1];
		i++;
	}
}

void	tab_int_ptr_rotate_left(int **ptr_tab, int length)
{
	int	i;
	int	*save;

	i = 1;
	save = ptr_tab[0];
	while (i != length)
	{
		ptr_tab[i - 1] = ptr_tab[i];
		i++;
	}
	ptr_tab[length - 1] = save;
}

void	tab_int_ptr_shift_left(int **ptr_tab, int length)
{
	int	i;

	i = 1;
	while (i != length)
	{
		ptr_tab[i - 1] = ptr_tab[i];
		i++;
	}
}
