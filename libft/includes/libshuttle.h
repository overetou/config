#ifndef	LIBSHUTTLE_H
#define LIBSHUTTLE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define LI long int
#define INT_MAX_LENGTH 10
#define BOOL char
#define SIZE unsigned int
#define string(name, size) char name[size]; name[size - 1] = 0;
#define	C_TYPES char* c_types[] = {"void", "char", "int", "BOOL", "size", NULL};

//keps track of the size of an int in term of chars. See find_mult_size.
typedef struct	mult_size_s
{
	int	mult;
	int	size;
}		mult_size_t;

typedef struct	simple_list_s
{
	void* content;
	struct simple_list_s* next;
}		simple_list_t;

//exit
void	exit_msg(const char *to_disp);
void	test_exit(void*	test_ptr, const char *msg);
void	exit_arrow(const char* str, int i, const char* msg);

//generic_manipulation
void	swap_pointer(void** p1, void** p2);
//void	swap_content(void* p1, void* p2);

//file manipulation
	//file_length
LI	flen(FILE *raw_file);
	//get
char    get_char(int file);
int     get_int(int raw_file, LI* to_travel, char separator);
void	get_code_line(int file, char*  prototype_buffer);
char	get_word(int file, char* to_fill, SIZE word_max_length);
//void	get_code_line(int file, char* buffer);
	//open_and_close. With fopen and opens with read only option
FILE*   open_file(char *file_name);
void    close_file(FILE* raw_file);
	//navigate
void	advance_and_check(int raw_file, char to_match, int to_cross, LI* to_travel);
void	go_next_line(int file);
	//C_language
BOOL	find_prototype_in_file(int file, char* prototype_buffer);

//directory_manipulation
	//directory_basic
BOOL	check_file_presence(simple_list_t* names, int length);

//string manipulation
	//put
void	putchr(const char c);
void	putstr(const char* str);
void	putendl(const char* str);
void	put_arrow(const char* str, int i);
void	putnb(const int n, const  mult_size_t meta);
void	quick_putnb(const int n);
void	puttab(const int* tab, int size);
	//string_basic
int	slen(const char* str);
char*	strnew(const char* str, int length);
int	copy_string(const char* source, char* recipient);
	//string_compare
int	strings_match(const char* str1, const char *str2);
BOOL	str_equals_any(char* str, char** candidates);
	//strtab_matching
int		chr_match_any_in_string(const char c, const char *array);
int		chr_match_in_any_string(const char c, const char **array_set);

//int manipulation
	//meta
void	find_mult_size(const int n, mult_size_t *to_fill);
	//int_compare
BOOL	cmp_tab(const int* tab1, const int* tab2, const int size);

//type_manipulation
	//type_question
BOOL	is_digit(char c);
BOOL	is_lowercase(char c);
BOOL	is_uppercase(char c);
BOOL	is_alpha(char c);
BOOL	is_alphanum(char c);
	//type_conversion
int	char_to_int(const char c);
int	str_to_int(const char* str);
int	str_to_int_sign(const char* str);
void	int_to_str(int n, char* buff, int mult);

//lists
	//simple_lists
//char		str_equals_any(const char* str, simple_list_t* strs);
simple_list_t*	allocate_simple_list(void);
simple_list_t*	init_simple_list(void* content);
void		add_link(simple_list_t** endlink, void* content);
void		initialize_simple_list(simple_list_t** link_tab, void* content);
void		destroy_list(simple_list_t* lst);

//parsing
	//simle_parsing
int	count_char(const char* str, char to_find);
	//input
int*	input_numbers(const char* str, int* tab_size);

#endif
