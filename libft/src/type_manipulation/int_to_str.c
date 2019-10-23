/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:33:34 by overetou          #+#    #+#             */
/*   Updated: 2019/10/23 18:15:38 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_to_str(int n, char* buff, int mult)
{
	int	i;

	i = 0;
	while (mult)
	{
		buff[i] = n / mult + '0';
		n = n - n / mult * mult;
		mult /= 10;
		i++;
	}
	buff[i] = 0;
}
