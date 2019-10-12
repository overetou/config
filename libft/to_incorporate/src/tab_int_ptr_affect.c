/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_int_ptr_affect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:03:00 by overetou          #+#    #+#             */
/*   Updated: 2019/06/18 17:31:30 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	affect_int_ptr_tab(int l, int s, int **ptr_tab, int int_tab[l][s])
{
	while (l--)
		ptr_tab[l] = int_tab[l];
}
