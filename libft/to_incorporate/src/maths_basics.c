/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:57:17 by overetou          #+#    #+#             */
/*   Updated: 2019/06/18 17:57:18 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sqr(int root)
{
	return (root * root);
}

int		pythagore(int side1, int side2)
{
	float add;

	add = (float)(sqr(side1) + sqr(side2));
	return ((int)squrt_2(add, find_float_length(add) % 2));
}
