/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:24:15 by overetou          #+#    #+#             */
/*   Updated: 2019/10/23 18:25:04 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_mult_size(const int n, mult_size_t *to_fill)
{
	to_fill->mult = 1;
	to_fill->size = 1;

	while (n / (to_fill->mult) > 9)
	{
		to_fill->mult *= 10;
		to_fill->size++;
	}
}
