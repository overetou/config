/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_travel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:27:03 by overetou          #+#    #+#             */
/*   Updated: 2019/04/19 20:05:30 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	loose_skip_space(char **str)
{
	if ((*str)[1] == ' ')
		*str += 2;
	else
		(*str)++;
}

void	strict_skip_space(char **str)
{
	if ((*str)[1] == ' ')
		*str += 2;
}

void	step_space(char **str)
{
	if (**str == ' ')
		(*str)++;
}
