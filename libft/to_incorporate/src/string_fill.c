/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:08:43 by overetou          #+#    #+#             */
/*   Updated: 2019/06/18 17:08:45 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_cpy(char *to_fill, const char *src, UINT ln)
{
	while (ln--)
		to_fill[ln] = src[ln];
}
