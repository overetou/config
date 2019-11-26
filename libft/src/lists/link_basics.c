#include "libft.h"

void    *link_advance_till_next_equals(t_link *l, void *to_match)
{
    while (l->next != to_match)
        l = l->next;
    return (l);    
}