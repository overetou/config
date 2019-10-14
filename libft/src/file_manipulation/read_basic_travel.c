/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_basic_travel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:10:41 by overetou          #+#    #+#             */
/*   Updated: 2019/07/08 15:52:31 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

BOOL	read_smart_inc(t_buf *b)
{
	b->pos++;
	if (b->pos >= b->length)
	{
		if (refresh_buf(b) < 1)
			return (0);
	}
	return (1);
}

BOOL	read_till_true(t_buf *b, BOOL (*func)(char))
{
	while (!func(b->str[b->pos]))
	{
		if (!read_smart_inc(b))
			return (0);
	}
	return (1);
}

BOOL	read_till_false(t_buf *b, BOOL (*func)(char))
{
	while (func(b->str[b->pos]))
	{
		if (!read_smart_inc(b))
			return (0);
	}
	return (1);
}

BOOL	find_and_skip(t_buf *b, BOOL (*func)(char))
{
	if (read_till_true(b, func))
	{
		read_till_false(b, func);
		return (1);
	}
	return (0);
}
