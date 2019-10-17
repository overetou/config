/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_simple_basics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:19:13 by overetou          #+#    #+#             */
/*   Updated: 2019/10/17 16:27:11 by overetou         ###   ########.fr       */
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
