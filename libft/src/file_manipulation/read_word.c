/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:26:05 by overetou          #+#    #+#             */
/*   Updated: 2019/10/24 16:45:19 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**This function must be launched on the first char of the word. Returns a string
**Containing the word.
*/
char	*read_word(t_buf *b, BOOL (*is_in_word_definition)(const char))
{
	char	*new;
	UINT	i;

	new = malloc(WORD_BUF_SIZE);
	new[0] = b->str[b->pos];
	i = 1;
	read_smart_inc(b);
	while (is_in_word_definition(b->str[b->pos]))
	{
		new[i] = b->str[b->pos];
		i++;
		read_smart_inc(b);
		if (i % WORD_BUF_SIZE == 0)
			new = realloc(new, i + WORD_BUF_SIZE);
	}
	new[i] = '\0';
	return (new);
}

//Returns the next word corresponding to the definition given in the func pointer.
//Returns NULL on failure (could not get a word before EOF).
char	*read_next_word(t_buf *b, BOOL (*is_in_word_definition)(const char))
{
	if (read_till_true(b, is_in_word_definition) == 0)
		return (NULL);
	return (read_word(b, is_in_word_definition));
}
