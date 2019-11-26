/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:07:09 by overetou          #+#    #+#             */
/*   Updated: 2019/10/25 17:57:58 by overetou         ###   ########.fr       */
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

//push the link at the start of the track
void	track_push(t_track *t, t_link *l)
{
	l->next = t->first;
	t->first = l;
}

void	link_track_init(t_link_track *t, t_link *l)
{
	t->first = l;
	t->last = l;
}

void	link_track_add(t_link_track *t, t_link *l)
{
	t->last->next = l;
	t->last = l;
}

void	track_insert_list(t_track *t, t_link *l)
{
	if (t->first == NULL)
	{
		track_init(t, l);
		l = l->next;
	}
	while (l != NULL)
	{
		track_add(t, l);
		l = l->next;
	}
}
