/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_char_trigger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:13:40 by overetou          #+#    #+#             */
/*   Updated: 2019/10/16 18:04:27 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

/*
**Returns -1 if EOF was reached without any match. Else returns the index of the matched string.
*/
int		file_match_next_char_arrays(t_buf *b, char *ar_set[])
{
	int i;

	if (b->length == 0)
		return (-1);
	while ((i = chr_match_in_any_stringlink(b->str[b->pos],
	(const char**)ar_set)) < 0)
	{
		if (read_smart_inc(b) < 1)
			return (-1);
	}
	return (i);
}

/*
**Till there is no more chars, if a char contained in a string is found, activate the corresponding function (by index). Returns 1 on success, else 0.
*/
BOOL	parse_and_trigger(t_buf *b, void *set)
{
	int	i;
	int n;
	BOOL            (*f)(t_buf*, void*);

	if (refresh_buf(b) == 0)
		return (0);
	while ((i = file_match_next_char_arrays(b, set.trigger_strings.first)) >= 0)
	{
		n = (f[i](b, args));
		if (n == 0)
			return (0);
		if (n == -1)
			return (1);
	}
	return (1);
}
