#include "libft.h"

int		find_smallest_non_null(UINT *tab, int tab_size)
{
	int	best_index;
	int	i;

	i = 0;
	while (i != tab_size && tab[i] == 0)
		i++;
	if (i == tab_size)
		return (-1);
	best_index = i;
	while (i != tab_size)
	{
		if (tab[i] && tab[i] < tab[best_index])
			best_index = i;
		i++;
	}
	return (best_index);
}

BOOL	tab_float_remaining_non_null(const float *tab, UINT i, UINT length)
{
	while (i != length)
	{
		if (tab[i])
			return (1);
		i++;
	}
	return (0);
}
void	neg_delta_display(const float *solutions)
{
	put_signed_float(*solutions);
	putstr(" + i * ");
	put_signed_float(-solutions[1]);
	putchr('\n');
	put_signed_float(*solutions);
	putstr(" + i * ");
	put_signed_float(solutions[1]);
	putchr('\n');
}

void	link_and_put(UINT last_p, float v, UINT p)
{
	while (last_p != p)
	{
		putstr(" + 0 * X^");
		quick_putnb(last_p, 1);
		last_p++;
	}
	putchr(' ');
	put_operation_float(v);
	putstr(" * X^");
	quick_putnb(p, 1);
}

BOOL	display_v_extr(float *v, float *xtr_v, UINT *cor_p)
{
	int		i;
	UINT	last_put;

	if (!tab_float_remaining_non_null(xtr_v, 0, 100))
		return (1);
	putstr("Reduced form: ");
	put_signed_float(*v);
	putstr(" * X^0 ");
	put_operation_float(v[1]);
	putstr(" * X^1 ");
	put_operation_float(v[2]);
	putstr(" * X^2");
	last_put = 2;
	while ((i = find_smallest_non_null(cor_p, 99)) != -1)
	{
		link_and_put(last_put + 1, xtr_v[i], cor_p[i]);
		last_put = cor_p[i];
		cor_p[i] = 0;
	}
	putstr(" = 0\nPolynomial degree is: ");
	quick_putnb(last_put, 1);
	putstr(".\nCan not solve, maximum supported degree is 2.\n");
	_exit(0);
}

//BOOL	put_reduced(const t_equ *e, float *v, UINT i)
//{
//	float	xtr_v[100];
//	UINT	cor_p[100];
//
//	fill_float_tab(xtr_v, 0, 100);
//	fill_uint_tab(cor_p, 0, 100);
//	while (i != e->pos)
//	{
//		if (e->ps[i].p >= MAX_DEGREE)
//		{
//			if (!ad_v(xtr_v, cor_p, i < e->e_po ? 1 : -1, e->ps[i]))
//				return (msg_false("Too much big powers."));
//		}
//		else
//			v[e->ps[i].p] += e->ps[i].c * (i < e->e_po ? 1 : -1);
//		i++;
//	}
//	return (display_v_extr(v, xtr_v, cor_p));
//}

void	display_simplified(const float *v)
{
	putstr("Reduced form: ");
	put_signed_float(*v);
	putstr(" * X^0 ");
	if (tab_float_remaining_non_null(v, 1, 3))
	{
		put_operation_float(v[1]);
		putstr(" * X^1 ");
	}
	if (tab_float_remaining_non_null(v, 2, 3))
	{
		put_operation_float(v[2]);
		putstr(" * X^2 ");
	}
	putendl("= 0");
}

void	display_solutions(const float *solutions, const UINT solution_nb)
{
	if (solution_nb == 0)
		putendl("Every real number is a solution.");
	else if (solution_nb == 1)
	{
		putendl("The solution is:");
		put_signed_float(*solutions);
		putchr('\n');
	}
	else if (solution_nb == 2)
	{
		put_signed_float(*solutions);
		putchr('\n');
		put_signed_float(solutions[1]);
		putchr('\n');
	}
	else if (solution_nb == 3)
	{
		neg_delta_display(solutions);
	}
	else
		putendl("There is no solution.");
}