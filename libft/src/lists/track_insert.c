/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:07:09 by overetou          #+#    #+#             */
/*   Updated: 2019/10/17 16:12:23 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	track_init(t_track *t, t_link *l)
{
	t->first = l;
	t->last = l;
}

/*
**Must be used on an already initialised track. (It must have at leat 1 link)
*/
void	track_add(t_track *t, t_link *l)
{
	t->last->next = l;
	t->last = l;
}
