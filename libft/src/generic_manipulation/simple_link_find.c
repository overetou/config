/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_link_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:21:38 by overetou          #+#    #+#             */
/*   Updated: 2019/10/24 15:51:15 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*get_link_content_by_index(t_simple *l, int i)
{
	while (i)
	{
		l = l->next;
		i--;
	}
	return (l->content);
}

void	*get_link_by_index(t_link *l, int i)
{
	while (i)
	{
		l = l->next;
		i--;
	}
	return (l);
}
