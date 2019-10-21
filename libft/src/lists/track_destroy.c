/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:04:08 by overetou          #+#    #+#             */
/*   Updated: 2019/10/21 16:50:37 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	destroy_track_from(t_link *start, t_link *end)
{
	t_link	*destroyer;

	while (start != end)
	{
		destroyer = start;
		start = start->next;
		free(destroyer);//just replace that func with a func pointer given in params to have a modular func.
	}
	free(end);
}
