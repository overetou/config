#include "libft.h"

//Swap/exchanges the value of two pointers.
void	swap_pointer(void** p1, void** p2)
{
	void*	swap;
	swap = *p1;
	*p1 = *p2;
	*p2 = swap;
}

//Swap/exchanges the content of two pointers.
//void	swap_content(unsigned long int* p1, unsigned long int* p2)
//{
//	*p1 = *p1 ^ *p2;
//	*p2 = *p1 ^ *p2;
//	*p1 = *p1 ^ *p2;
//}
