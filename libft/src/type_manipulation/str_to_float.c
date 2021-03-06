/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:26:33 by overetou          #+#    #+#             */
/*   Updated: 2019/10/30 16:59:39 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	char_to_float(char c)
{
	return ((float)(c - '0'));
}

char	float_to_chr(float f)
{
	return ((char)(((int)f) + '0'));
}
