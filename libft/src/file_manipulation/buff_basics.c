/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:00:57 by overetou          #+#    #+#             */
/*   Updated: 2019/07/03 19:24:31 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include <unistd.h>

BOOL	refresh_buf(t_buf *b)
{
	b->length = read(b->fd, b->str, BUFFSIZE);
	b->pos = 0;
	if ((b->length) <= 0)
		return (0);
	return (1);
}
