/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:04:08 by overetou          #+#    #+#             */
/*   Updated: 2019/11/20 16:29:58 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	destroy_track_from_to(t_link *start, t_link *end, void (*free_func)(void*))
{
	t_link	*destroyer;

	while (start != end)
	{
		destroyer = start;
		start = start->next;
		free_func(destroyer);//just replace that func with a func pointer given in params to have a modular func.
	}
	free_func(end);
}

void	destroy_track(t_track *t, void (*free_func)(void*))
{
	if (t->first)
	{
		destroy_track_from_to(t->first, t->last, free_func);
		t->first = NULL;
	}
}

void	track_remove_last(t_track *t, void (*free_func)(void*))
{
	t_link*	l;

	l = t->first;
	while (l->next != t->last)
		l = l->next;
	free_func(t->last);
	t->last = l;
}

void	destroy_link_track_content(t_link_track* t)
{
	t_link	*l;
	t_link	*destroyer;

	l = ((t_link_track*)t)->first;
	if (l == NULL)
		return ;
	while (l != ((t_link_track*)t)->last)
	{
		destroyer = l;
		l = l->next;
		if (destroyer == NULL)
			putendl("Attempting to free a NULL");
		free(destroyer);
	}
	free(l);
	t->first = NULL;
}

void	destroy_link_track(void	*t)
{
	destroy_link_track_content(t);
	free(((t_link_track*)t));
}

void	link_track_remove_link(t_link_track *t, t_link *l)
{
	t_link *cur;
	t_link *next;

	if (t->first == t->last)
		t->first = NULL;
	else if (l == t->first)
	{
		cur = t->first;
		t->first = cur->next;
		free(cur);
	}
	else
	{
		cur = link_advance_till_next_equals(t->first->next, l);
		if (cur->next == t->last)
		{
			free(t->last);
			t->last = cur;
			return;
		}
		next = cur->next->next;
		free(cur->next);
		cur->next = next;
	}
}