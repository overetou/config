/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:01:21 by overetou          #+#    #+#             */
/*   Updated: 2019/06/27 19:21:45 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	open_check(const char *file_name, const char *extension, int option)
{
	int	memory;

	memory = (int)len_str(file_name);
	memory = string_reverse_find(file_name, '.', memory);
	if (memory > 0 && str_perfect_match(file_name + memory, extension))
		return (open(file_name, option));
	return (-1);
}
