#ifndef	LIBSHUTTLE_H
#define LIBSHUTTLE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define LI long int
#define UINT unsigned int
#define INT_MAX_LENGTH 10
#define BOOL char
#define SIZE unsigned int
#define string(name, size) char name[size]; name[size - 1] = 0;
#define	C_TYPES char* c_types[] = {"void", "char", "int", "BOOL", "size", NULL};
#define BUFFSIZE 100

//keps track of the size of an int in term of chars. See find_mult_size.
typedef struct	mult_size_s
{
	int	mult;
	int	size;
}		mult_size_t;

typedef struct	s_link
{
	struct s_link	*next;
}				t_link;

typedef struct	s_track
{
	t_link		*first;
	t_link		*last;
}				t_track;

typedef struct	s_buf
{
	char		str[BUFFSIZE];
	int			length;
	int			pos;
	int			fd;
}				t_buf;

//exit
void	exit_msg(const char *to_disp);
void	test_exit(void*	test_ptr, const char *msg);
void	exit_arrow(const char* str, int i, const char* msg);

//generic_manipulation
	//pointer_basics
void	swap_pointer(void** p1, void** p2);
	//mem_assign
void	mcopy(char *src, char *dest, const UINT s);
//void	swap_content(void* p1, void* p2);

//file manipulation
	//file_length
LI	flen(FILE *raw_file);
	//buff_basics
BOOL	refresh_buf(t_buf *b);
	//fd_basics
void	rewind_file(const int fd);
	//read_basic_travel
BOOL	read_smart_inc(t_buf *b);
BOOL	read_till_true(t_buf *b, BOOL (*func)(char));
BOOL	read_till_false(t_buf *b, BOOL (*func)(char));
BOOL	find_and_skip(t_buf *b, BOOL (*func)(char));
	//read_char_trigger
int		file_match_next_char_arrays(t_buf *b, char *ar_set[]);
BOOL	parse_and_trigger(t_buf *b, void *args, char *s[], BOOL (*f[2])(t_buf*, void*));
	//wrap_open
int	open_check(const char *file_name, const char *extension, int option);

//directory_manipulation
	//directory_basic

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
UINT	compare_str(const char *str1, const char *str2);
BOOL	str_match(const char *str1, const char *str2);
BOOL	str_perfect_match(const char *str1, const char *str2);
BOOL	str_equals_any(char *str, char **candidates);
	//strtab_matching
int		chr_match_any_in_string(const char c, const char *array);
int		chr_match_in_any_string(const char c, const char **array_set);
	//string_link_match
int	chr_match_in_any_stringlink(const char c, t_simple *s);
	//string_find
int	string_reverse_find(const char *str, const char to_find, int searchable_s);

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

//parsing
	//simle_parsing
int	count_char(const char* str, char to_find);
	//input
int*	input_numbers(const char* str, int* tab_size);

#endif
