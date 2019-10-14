/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_char_trigger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:13:40 by overetou          #+#    #+#             */
/*   Updated: 2019/07/08 15:48:56 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int		file_match_next_char_arrays(t_buf *b, char *ar_set[])
{
	int i;

	if (b->length == 0)
		return (-1);
	while ((i = chr_match_any_array(b->str[b->pos],
	(const char**)ar_set)) < 0)
	{
		if (read_smart_inc(b) < 1)
			return (-1);
	}
	return (i);
}

BOOL	parse_and_trigger(t_buf *b, void *args, char *s[], BOOL (*f[2])(t_buf*, void*))
{
	int	i;
	int n;

	if (refresh_buf(b) == 0)
		return (0);
	while ((i = file_match_next_char_arrays(b, s)) >= 0)
	{
		if (!(n = (f[i](b, args))))
			return (0);
		if (n == -1)
			return (1);
	}
	return (1);
}
