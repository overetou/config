/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_put_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:21:39 by overetou          #+#    #+#             */
/*   Updated: 2019/04/17 17:02:49 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_int_rect_table(const int **tab, const int col_nb, const int line_nb)
{
	int y;

	y = 0;
	while (y != line_nb)
	{
		put_uint_tab((const UINT*)(tab[y]), (UINT)col_nb);
		y++;
	}
}

void	put_uint_tab(const UINT *tab, const UINT tab_size)
{
	UINT	i;

	put_char('[');
	put_nb(tab[0], find_nb_length(tab[0]));
	i = 1;
	while (i != tab_size)
	{
		put_str(", ");
		put_nb(tab[i], find_nb_length(tab[i]));
		i++;
	}
	put_str("]\n");
}

void	put_float_tab(const float *tab, const UINT tab_size)
{
	UINT	i;

	put_char('[');
	put_signed_float(tab[0]);
	i = 1;
	while (i != tab_size)
	{
		put_str(", ");
		put_signed_float(tab[i]);
		i++;
	}
	put_str("]\n");
}
