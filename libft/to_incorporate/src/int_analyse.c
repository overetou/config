/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_analyse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:58:12 by overetou          #+#    #+#             */
/*   Updated: 2019/06/18 17:58:13 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	int_is_comprised(const int n, const int lowest, const int highest)
{
	return (n >= lowest && n <= highest);
}
