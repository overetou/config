/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:47:27 by overetou          #+#    #+#             */
/*   Updated: 2019/10/17 17:02:04 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	trigger_init(t_trigger_set *set, const char *str, char (*f)(t_buf*, void*))
{
	track_init(&(set->trigger_strings), (t_link*)t_simple_create(strnew(str, slen(str))));
	track_init(&(set->trigger_funcs), (t_link*)t_simple_create(f));
}

void	trigger_add(t_trigger_set *set, const char *str, char (*f)(t_buf*, void*))
{
	track_add(&(set->trigger_strings), (t_link*)t_simple_create(strnew(str, slen(str))));
	track_add(&(set->trigger_funcs), (t_link*)t_simple_create(f));
}
