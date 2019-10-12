/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:24:27 by overetou          #+#    #+#             */
/*   Updated: 2019/03/18 17:24:29 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	put_char(const char c)
{
	write(1, &c, 1);
}

void	put_str(const char *s)
{
	write(1, s, len_str(s));
}

void	dry_put_str(const char *str, UINT length)
{
	write(1, str, length);
}

void	put_endl_str(const char *s)
{
	put_str(s);
	write(1, "\n", 1);
}
