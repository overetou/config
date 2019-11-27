#include "libft.h"
#include <stdio.h>

t_link_track	*link_track_create(t_link *l)
{
	t_link_track	*new;

	new = malloc(sizeof(t_link_track));
	link_track_init(new, l);
	return (new);
}

void	track_replace_link_with_list(t_track *t, t_link *to_replace, t_link *list)
{
	track_insert_list(t, list);
	track_remove_link(t, to_replace);
}

//This func is used to put all non processed expr at the start of the list.
void	track_push_internal_link(t_link *l, t_track *t)
{
	t_link	*prev;

	if (l != (void*)(t->first))
	{
		prev = link_advance_till_next_equals(t->first, l);
		prev->next = l->next;
		track_push(t, l);
	}
}

void	link_track_push_internal_link(t_link *l, t_link_track *t)
{
	t_link	*prev;

	if (l != (void*)(t->first))
	{
		prev = link_advance_till_next_equals(t->first, l);
		prev->next = l->next;
		link_track_push(t, l);
	}
}