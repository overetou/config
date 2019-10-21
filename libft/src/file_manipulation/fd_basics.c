/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:00:33 by overetou          #+#    #+#             */
/*   Updated: 2019/10/21 16:57:47 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	rewind_file(const int fd)
{
	lseek(fd, 0, SEEK_SET);
}

void	open_stdin(t_buf *b)
{
	b->fd = 0;
}
