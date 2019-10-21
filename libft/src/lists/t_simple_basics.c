/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_simple_basics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:19:13 by overetou          #+#    #+#             */
/*   Updated: 2019/10/21 16:49:48 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_simple	*t_simple_create(void *content)
{
	t_simple	*new;

	new = malloc(sizeof(t_simple));
	new->content = content;
	return (new);
}

t_simple  *create_void_simple(void)
{
	t_simple	*new;

    new = calloc(1, sizeof(t_simple));
    test_exit(new, "Call to calloc failed.");
    return (new);
}

void	*t_simpl_content(void* link)
{
	return (((t_simple*)(link))->content);
}
