/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_link_match.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:49:07 by overetou          #+#    #+#             */
/*   Updated: 2019/10/23 16:50:14 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	chr_match_in_any_stringlink(const char c, t_track *string_links)
{
	int	i;
	t_simple *current_link;

	i = 0;
	current_link = (void*)(string_links->first);
	while (1)
	{
		if (chr_match_any_in_string(c, current_link->content) != -1)
			return (i);
		if (current_link == (void*)(string_links->last))
			return (-1);
		i++;
		current_link = current_link->next;
	}
}
