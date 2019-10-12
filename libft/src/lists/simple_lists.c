#include <libshuttle.h>

////This function is flexible as it allows to process variable number of strings. You won't need to repeat strings_match in conditions anymore.
//char		str_equals_any(const char* str, simple_list_t* strs)
//{
//	while (strs)
//	{
//		if (strings_match(str, (char*)(strs->content)))
//			return (1);
//		strs = strs->next;
//	}
//	return (0);
//}
//
void		destroy_list(simple_list_t* lst)
{
	simple_list_t* ranger;
	while (lst)
	{
		ranger = lst->next;
		free(lst);
		lst = ranger;
	}
}

simple_list_t*	allocate_simple_list(void)
{
	return ((simple_list_t*)malloc(sizeof(simple_list_t)));
}

simple_list_t* init_simple_list(void* content)
{
	simple_list_t* link = allocate_simple_list();
	link->content = content;
	return (link);
}

//This func adds a link and updates its param to stay the endlink.
void		add_link(simple_list_t** endlink, void* content)
{
	(*endlink)->next = init_simple_list(content);
	*endlink = (*endlink)->next;
}


//tab[0] is meant to be the start link and tab[1] the endlink.
void	initialize_simple_list(simple_list_t** link_tab, void* content)
{
	link_tab[0] = init_simple_list(content);
	link_tab[1] = link_tab[0];
}

