/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:12:38 by bbear             #+#    #+#             */
/*   Updated: 2019/01/20 02:32:59 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		puttmap(t_map **map, t_figure *figure, int *cord)
{
	int		i;
	int		newx;
	int		newy;
	char	**mp;
	int		count;

	i = 0;
	count = 0;
	mp = (*map)->map;
	while (i < 4)
	{
		newx = cord[0] + figure->coordinates[i].x;
		newy = cord[1] + figure->coordinates[i].y;
		if (newx < (*map)->size && newy < (*map)->size && mp[newy][newx] == '.')
		{
			mp[newy][newx] = figure->letter;
			count++;
		}
		if (newx >= (*map)->size || newy >= (*map)->size)
			return (0);
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

void	delfig(t_map **map, t_figure *figure)
{
	char	**mp;
	int		size;
	char	letter;
	int		x;
	int		y;

	y = 0;
	letter = figure->letter;
	mp = (*map)->map;
	size = (*map)->size;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (mp[y][x] == letter)
				mp[y][x] = '.';
			x++;
		}
		y++;
	}
}

int		recursion(t_map **map, t_list *figures)
{
	char		**mp;
	int			cord[2];
	int			flag;

	cord[1] = -1;
	mp = (*map)->map;
	while (++cord[1] < (*map)->size)
	{
		cord[0] = -1;
		while (++cord[0] < (*map)->size && figures != NULL)
		{
			if ((flag = puttmap(map, figures->content, cord)))
			{
				if (!recursion(map, figures->next))
					delfig(map, figures->content);
				else
					return (1);
			}
			else
				delfig(map, figures->content);
		}
	}
	if (!figures)
		return (1);
	return (0);
}

void	solution(t_list *figures)
{
	int			mapsize;
	t_map		*map;
	int			i;
	t_figure	*fig;

	i = 0;
	fig = figures->content;
	mapsize = ft_sqrt(countfig(figures) * 4);
	map = createmap(mapsize);
	while (!recursion(&map, figures))
	{
		map = mapresize(&map);
		mapsize++;
	}
	while (i < mapsize)
	{
		ft_putendl(map->map[i]);
		i++;
	}
}
