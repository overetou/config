#include "libft.h"
#include <stdio.h>

t_link_track	*link_track_create(t_link *l)
{
	t_link_track	*new;

	new = malloc(sizeof(t_link_track));
	link_track_init(new, l);
	return (new);
}

void	link_track_replace_link_with_list(t_link_track *t, t_link *to_replace, t_link *list)
{
	link_track_insert_list(t, list);
	putendl("link_track_replace_link_with_list: link_track_insert_list passed");
	link_track_remove_link(t, to_replace);
}

t_link *create_list_copy(t_link *l, t_link*(*copy_func)(t_link*))
{
	t_link	*new;
	t_link	*head;

	new = copy_func(l);
	head = new;
	l = l->next;
	while (l)
	{
		putendl("create list copy: one loop in the while.");
		head->next = copy_func(l);
		l = l->next;
		head = head->next;
	}
	head->next = NULL;
	putendl("appended a NULL at the end of the list.");
	return (new);
}

void	link_track_insert_list_copy(t_link_track *t, t_link *l, t_link*(*copy_func)(t_link*))
{
	link_track_insert_list(t, create_list_copy(l, copy_func));
}

t_link*	link_track_replace_link_with_list_copy(t_link_track *t, t_link *to_replace, t_link *list, t_link*(*copy_func)(t_link*))
{
	link_track_insert_list_copy(t, list, copy_func);
	putendl("link_track_replace_link_with_list: link_track_insert_list passed");
	link_track_remove_link(t, to_replace);
	return (t->first);
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