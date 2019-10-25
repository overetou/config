#include "libft.h"

t_link_track	*link_track_create(t_link *l)
{
	t_link_track	*new;

	new = malloc(sizeof(t_link_track));
	link_track_init(new, l);
	return (new);
}
