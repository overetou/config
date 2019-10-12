/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:12:05 by overetou          #+#    #+#             */
/*   Updated: 2019/10/12 16:51:27 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define LI long int
# define BOOL char
# define UINT unsigned int
# define UCHR unsigned char
# define USHT unsigned short
# define CINT const int
# define CUINT const unsigned int
# define CFLT const float
# define CCHAR const char
# define INT_MAX_SIZE  10
# define BUFFSIZE 300

typedef struct	s_link
{
	struct s_link	*next;
}				t_link;

typedef struct	s_track
{
	t_link		*first;
	t_link		*last;
}				t_track;

typedef struct	s_stght
{
	int			*origin;
	int			*dest;
}				t_stght;

typedef struct	s_buf
{
	char		str[BUFFSIZE];
	int			length;
	int			pos;
	int			fd;
}				t_buf;

UINT			compare_str(CCHAR *str1, CCHAR *str2);
BOOL			str_match(CCHAR *str1, CCHAR *str2);
BOOL			str_perfect_match(CCHAR *str1, CCHAR *str2);
BOOL			str_equals_any(char *str, char **candidates);
void			put_char(CCHAR c);
void			put_str(CCHAR *s);
void			dry_put_str(CCHAR *str, UINT length);
void			put_endl_str(CCHAR *s);
void			put_nb(UINT n, UINT nb_size);
void			put_decimal(float f);
void			put_float(float f);
UINT			len_str(CCHAR *s);
void			test(BOOL success, CCHAR *name);
void			loose_skip_space(char **str);
void			strict_skip_space(char **str);
void			step_space(char **str);
BOOL			msg_true(CCHAR *str);
BOOL			msg_false(CCHAR *str);
UINT			str_get_uint_size(CCHAR *str);
int				str_get_int(CCHAR *str, UINT nb_size);
int				str_get_signed_int(CCHAR *str, UINT nb_size);
BOOL			read_number(t_buf *b, int *to_fill);
BOOL			read_next_number(t_buf *b, int *to_fill);
void			fill_float_tab(float *tab, float value, UINT length);
BOOL			is_digit(CCHAR c);
BOOL			is_sign_or_digit(CCHAR c);
float			parse_float(char *str, UINT *float_size);
float			parse_decimals(char *str, UINT nb_size);
float			float_abs(float f);
BOOL			float_equ(float f1, float f2);
BOOL			compare_catched_output(CCHAR *str, UINT lenstr);
void			catch_output(void);
float			find_divider(float n, float stop);
UINT			find_nb_length(UINT n);
float			squrt_2(float n, char is_par);
int				sqr(int root);
int				pythagore(int side1, int side2);
void			tab_int_cpy(CINT *src, int *targ, USHT length);
void			add_int_vectors(int *add1, int *add2, int *result, USHT size);
UINT			find_float_length(float f);
void			put_signed_float(float f);
BOOL			no_remaining_decimal(float f, UINT i);
void			put_operation_float(float f);
UINT			tab_find_first_cor_or_null(UINT to_find, UINT *tab);
void			fill_uint_tab(UINT *tab, UINT value, UINT length);
void			put_uint_tab(CUINT *tab, CUINT tab_size);
void			put_int_rect_table(CINT **tab, CINT col_nb, CINT line_nb);
BOOL			tab_uint_remaining_non_null(CUINT *tab, UINT i, UINT length);
BOOL			tab_float_remaining_non_null(CFLT *tab, UINT i, UINT length);
void			put_float_tab(CFLT *tab, CUINT tab_size);
BOOL			float_ad_excess(CFLT first, CFLT second);
int				string_reverse_find(CCHAR *str, CCHAR to_find, int srchable_s);
BOOL			refresh_buf(t_buf *b);
void			rewind_file(CINT fd);
void			dual_incrementation(int *n1, UINT *n2);
void			rect_increment(int *tab, CINT col_nb);
BOOL			str_int_too_big(CCHAR *str, UINT s, CINT nb, CINT sign);
int				str_get_int_with_sign(CCHAR *str, UINT nb_size, int sign);
BOOL			is_endline(CCHAR c);
int				chr_match_any_in_array(CCHAR c, CCHAR *array);
int				chr_match_any_array(CCHAR c, CCHAR **array_set);
BOOL			read_smart_inc(t_buf *b);
BOOL			pa_trg(t_buf *b, void *a, char *s[],
				BOOL (*f[2])(t_buf*, void*));
BOOL			read_till_false(t_buf *b, BOOL(*func)(char));
BOOL			read_till_true(t_buf *b, BOOL(*func)(char));
BOOL			int_is_comprised(CINT n, CINT lowest, CINT highest);
BOOL			int_roof(int *to_fill, CINT rocket, CINT roof);
void			tab_int_shift_left(int *tab, CUINT tab_length);
void			tab_int_ptr_rotate_left(int **ptr_tab, int length);
void			tab_int_ptr_shift_left(int **ptr_tab, int length);
void			affect_int_ptr_tab(int l, int s, int **p_tab, int int_tb[l][s]);
void			get_stght_abs_limits(t_stght *s1, t_stght *s2, int *u, int *d);
int				*crosspt(t_stght *seg1, t_stght *seg2, int crosspt[2]);
void			swap_ptr(void **p1, void **p2);
void			swap_int(int *a, int *b);
int				*tab_coord(int *tab, int x, int y);
t_stght			*stght(t_stght *st, int *ori, int *dst);
int				open_check(CCHAR *fl_name, CCHAR *ext, int option);
void			str_cpy(char *to_fill, CCHAR *src, UINT ln);
#endif
