/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_switch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:57:37 by overetou          #+#    #+#             */
/*   Updated: 2019/06/18 17:57:49 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	int_roof(int *to_fill, const int rocket, const int roof)
{
	if (rocket > roof)
	{
		*to_fill = roof;
		return (1);
	}
	*to_fill = rocket;
	return (0);
}
