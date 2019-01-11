/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:12:38 by bbear             #+#    #+#             */
/*   Updated: 2019/01/11 18:44:31 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solution(t_list *figures)
{
	int		mapsize;
	t_map	*map;
	int		i;

	i = 0;
	mapsize = ft_sqrt(countfig(figures) * 4);
	map = createmap(mapsize);
	while (i < mapsize)
	{
		ft_putendl(map->map[i]);
		i++;
	}
}
