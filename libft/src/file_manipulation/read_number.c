/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:28:15 by overetou          #+#    #+#             */
/*   Updated: 2019/10/22 19:08:01 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Expects that n points on 1 or -1 and that buf is positionned on the first digit
//of the number. Returns 0 on overflow and 1 on success.
char	read_int(t_buf *b, int *n)
{
	int	mem;
	int count;

	count = 0;
	mem = *n * char_to_int(b->str[b->pos]);
	while (read_smart_inc(b) && is_digit(b->str[b->pos]))
	{
		if (int_have_different_sign(*n, mem))
			return (0);
		*n = mem;
		mem = mem * 10 + char_to_int(b->str[b->pos]);
	}
	return (1);
}
