/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_msg_return.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:09:54 by overetou          #+#    #+#             */
/*   Updated: 2019/03/18 18:10:52 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	msg_false(const char *str)
{
	put_endl_str(str);
	return (0);
}

BOOL	msg_true(const char *str)
{
	put_endl_str(str);
	return (1);
}
