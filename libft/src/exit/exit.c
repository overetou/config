#include "libshuttle.h"

//Display a message passed as argument and exits.
void	exit_msg(const char* to_disp)
{
	putendl(to_disp);
	exit(0);
}

//test passed assesment. If true, nothing happens. If false, calls exit_msg with passed string.
void		test_exit(void*	test_ptr, const char* msg)
{
	if (!test_ptr)
		exit_msg(msg);
}

//Exits after putting an arrow on the problem.
void		exit_arrow(const char* str, int i, const char* msg)
{
			putendl(msg);
			put_arrow(str, i);
			exit(0);
}
