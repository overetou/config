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
/*
**Used in read_word.
*/
#define WORD_BUF_SIZE 10


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

typedef struct	s_simple
{
	struct s_simple *next;
	void			*content;
}				t_simple;

typedef struct	s_track
{
	t_link		*first;
	t_link		*last;
}				t_track;

typedef struct	s_link_track
{
	struct s_link_track	*next;
	t_link		*first;
	t_link		*last;
}				t_link_track;

typedef struct	s_link_track_two_last
{
	struct s_link_track	*next;
	t_link		*first;
	t_link		*last;
	t_link		*before_last;
}				t_link_track_two_last;

typedef struct	s_trigger_set
{
	t_track         trigger_strings;
	t_track         trigger_funcs;
}				t_trigger_set;

typedef struct	s_buf
{
	char		str[BUFFSIZE];
	int			length;
	int			pos;
	int			fd;
}				t_buf;

//maths
	//square_root
float	squrt_1(const float n);
float	find_piece(const float part, const float limit, float *candidate);
float	sqrt_past_point(float n, float remain, float result, UINT multiplier);
float	squrt_2(float n, char is_par);
	//resolution
void	resolve_first_degree(float *v, float *solutions);
UINT	resolve_second_degree(float *v, float *solutions);
int		do_resolution(float *v, unsigned int size, float *solutions);
	//equ_sol_display
void	display_solutions(const float *solutions, const UINT solution_nb);

//exit
void	exit_msg(const char *to_disp);
void	test_exit(void*	test_ptr, const char *msg);
void	exit_arrow(const char* str, int i, const char* msg);
void	*null_msg(const char *s);

//generic_manipulation
	//pointer_basics
void	swap_pointer(void** p1, void** p2);
	//mem_assign
void	mcopy(char *src, char *dest, const UINT s);
//void	swap_content(void* p1, void* p2);
	//simple_link_find
void	*get_link_content_by_index(t_simple *l, int i);
void	*get_link_by_index(t_link *l, int i);

//file manipulation
	//file_length
LI	flen(FILE *raw_file);
	//buff_basics
BOOL	refresh_buf(t_buf *b);
	//fd_basics
void	rewind_file(const int fd);
void	open_stdin(t_buf *b);
	//read_basic_travel
BOOL	read_smart_inc(t_buf *b);
BOOL	read_till_true(t_buf *b, BOOL (*func)(const char));
BOOL	read_till_false(t_buf *b, BOOL (*func)(const char));
BOOL	find_and_skip(t_buf *b, BOOL (*func)(const char));
BOOL	read_go_next_line(t_buf *b);
BOOL	read_skip_till_c(t_buf *b, const char c);
	//read_char_trigger
int		file_match_next_strset(t_buf *b, t_track *string_links);
BOOL	parse_and_trigger(t_buf *b, t_trigger_set *set);
	//wrap_open
int	open_check(const char *file_name, const char *extension, int option);
	//read_word
char	*read_word(t_buf *b, BOOL (*is_in_word_definition)(const char));
char	*read_next_word(t_buf *b, BOOL (*is_in_word_definition)(const char));
	//read_number
char	read_int(t_buf *b, int *n);
char	read_float(t_buf *b, float *n);

//directory_manipulation
	//directory_basic

//string manipulation
	//put
void	putchr(const char c);
void	putstr(const char* str);
void	putendl(const char* str);
void	put_arrow(const char* str, int i);
void	putnb(const int n, const  mult_size_t meta, BOOL display_minus);
void	quick_putnb(const int n, BOOL display_minus);
void	puttab(const int* tab, int size);
	//put_less_common
void	dry_putstr(char *s, int size);
void	quick_put_float(float f, BOOL display_minus);
void	put_signed_float(float f);
void	put_operation_float(float f);
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
int	chr_match_in_any_stringlink(const char c, t_track *string_links);
	//string_find
int	string_reverse_find(const char *str, const char to_find, int searchable_s);

//int manipulation
	//int_simple
void update_if_superior(size_t *to_update, size_t candidate);
	//meta
void	find_mult_size(const int n, mult_size_t *to_fill);
	//int_compare
BOOL	cmp_tab(const int* tab1, const int* tab2, const int size);
BOOL	int_have_different_sign(int n1, int n2);
int		int_is_comprised(int n, int first, int last);

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
	//str_to_float
float	char_to_float(char c);
char	float_to_chr(float f);
	//float
float	get_float_tail(float f);
BOOL	float_have_different_sign(float n1, float n2);
BOOL	float_simple_power(float *to_power, int power);

//lists
	//link_basics
t_link    *link_advance_till_next_equals(t_link *l, void *to_match);
	//track_insert
void	track_add(t_track *t, t_link *l);
void	track_push(t_track *t, t_link *l);
void	link_track_push(t_link_track *t, t_link *l);
void	track_init(t_track *t, t_link *l);
void	link_track_add(t_link_track *t, t_link *l);
void	link_track_init(t_link_track *t, t_link *l);
void	link_track_insert_list(t_link_track *t, t_link *l);
	//track_destroy
void	destroy_track_from_to(t_link *start, t_link *end, void (*free_func)(void*));
void	destroy_track(t_track *t, void (*free_func)(void*));
void	track_remove_last(t_track *t, void (*free_func)(void*));
void	destroy_link_track_content(t_link_track* t);
void	destroy_link_track(void *t);
void	link_track_remove_link(t_link_track *t, t_link *l);
	//t_simple_basics
t_simple	*t_simple_create(void *content);
t_simple	*create_void_simple(void);
void	*t_simpl_content(void* link);
	//track_create
t_link *create_list_copy(t_link *l, t_link*(*copy_func)(t_link*));
t_link_track	*link_track_create(t_link *l);
void	link_track_replace_link_with_list(t_link_track *t, t_link *to_replace, t_link *list);
t_link	*link_track_replace_link_with_list_copy(t_link_track *t, t_link *to_replace, t_link *list, t_link*(*copy_func)(t_link*));
void	track_push_internal_link(t_link *l, t_track *t);
void	link_track_push_internal_link(t_link *l, t_link_track *t);

//parsing
	//simple_parsing
int	count_char(const char* str, char to_find);
	//input
int*	input_numbers(const char* str, int* tab_size);
	//trigger_init
void	trigger_init(t_trigger_set *set, const char *str, char (*f)(t_buf*, void*));
void	trigger_add(t_trigger_set *set, const char *str, char (*f)(t_buf*, void*));

#endif