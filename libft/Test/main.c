#include "../includes/libshuttle.h"
#include <stdio.h>

void	test(BOOL passed)
{
	if (passed)
		putchr('.');
	else
		putstr("x\n");
}

BOOL	char_to_int_test()
{
	if (char_to_int('0') == 0 && char_to_int('9' == 9))
		return (1);
	putendl("char to int failed.");
	return (0);
}

BOOL	str_to_int_test()
{
	if (str_to_int("aloca") == 0 && str_to_int("12548") == 12548)
		return (1);
	putendl("str_to_int() failed pitifully.");
	return (0);
}

BOOL	slen_test(void)
{
	if (slen("cou") == 3)
		return (1);
	printf("slen(cou) = %d\n", slen("cou"));
	return (0);
}

BOOL	count_char_test()
{
	if (count_char("Salut les amis sosSi.", 's') == 4 && count_char("yoyoyoyoyooty", 'y') == 6)
		return (1);
	putendl("Count char failed");
	return (0);
}

BOOL	input_numbers_test(void)
{
	int	tabsize;
	int* tab = input_numbers("15,17,2,0,5", &tabsize);
	if (tab[0] == 15 && tab[1] == 17 && tab[2] == 2 && tab[3] == 0 && tab[4] == 5 && tabsize == 5)
		return (1);
	putendl("Input numbers failed !");
	return (0);
}

//BOOL	cmpstr_test(void)
//{
//	if (cmpstr("sum", "sum") == 3 && cmpstr("sumi", "sum") == 0 && cmpstr("sum", "sumo") == 0)
//		return (1);
//	putendl("cmpstr test failed.");
//	return (0);
//}

//BOOL	swap_test(void)
//{
//	int plutot = 6;
//	int fernand = 3;
//
//	swap_pointer((void**)(&boom), (void**)(&mac));
//	if (cmpstr(boom, "Mabotaco!") && cmpstr(mac, "Yoman!"))
//		return (1);
//	putendl("swap_tests failed.");
//	putstr(boom);putstr(" || ");putstr(mac);
//	return (0);
//}

BOOL	strings_match_test(void)
{
	if (strings_match("int", "int"))
		return (1);
	putendl("strings_match_test was defeated.");
	return (0);
}

int	main(void)
{
	test(slen_test());
	test(char_to_int_test());
	test(str_to_int_test());
	test(slen_test());
	test(count_char_test());
	test(input_numbers_test());
	test(strings_match_test());
//	test(cmpstr_test());
//	swap_test();
	char dest[] = "xxx";
	quick_putnb(5);
	putchr('\n');
	return (0);
}
