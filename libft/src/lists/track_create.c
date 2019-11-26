#include "libft.h"

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