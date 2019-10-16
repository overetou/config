/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_link_match.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:49:07 by overetou          #+#    #+#             */
/*   Updated: 2019/10/16 17:56:31 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	chr_match_in_any_stringlink(const char c, t_simple *s)
{
	int	i;

	i = 0;
	while (s)
	{
		if (chr_match_any_in_string(c, s->content) != -1)
			return (i);
		i++;
		s = s->next;
	}
	return (-1);
}
