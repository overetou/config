/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_char_trigger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:13:40 by overetou          #+#    #+#             */
/*   Updated: 2019/10/18 19:21:27 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Returns -1 if EOF was reached without any match. Else returns the index of the matched string.
*/
int		file_match_next_strset(t_buf *b, t_simple *s)
{
	int i;

	if (b->length == 0)
		return (-1);
	while ((i = chr_match_in_any_stringlink(b->str[b->pos], s) < 0))
	{
		if (read_smart_inc(b) < 1)
			return (-1);
	}
	return (i);
}

/*
**Till there is no more chars, if a char contained in a string is found, activate the corresponding function (by index). Returns 1 on success, else 0.
**Funcs must return 1 on success, 0 on critical failure and -1 to successfully interupt the parsing.
*/
BOOL	parse_and_trigger(t_buf *b, t_trigger_set *set)
{
	int		i;
	char	n;
	char	(*f)(t_buf*, void*);

	if (refresh_buf(b) == 0)
		return (0);
	while ((i = file_match_next_strset(b, (t_simple*)(set->trigger_strings.first))) >= 0)
	{
		f = (char (*)(t_buf*, void*))get_link_content_by_index((t_simple*)(set->trigger_funcs.first), i);
		n = (f(b, (void*)set));
		if (n == 0)
			return (0);
		if (n == -1)
			return (1);
	}
	return (1);
}
