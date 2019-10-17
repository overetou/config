/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_link_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:21:38 by overetou          #+#    #+#             */
/*   Updated: 2019/10/16 18:24:02 by overetou         ###   ########.fr       */
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
