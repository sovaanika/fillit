/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:39:22 by bbear             #+#    #+#             */
/*   Updated: 2019/01/12 16:30:55 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int		res;

	res = 1;
	while (res * res != nb)
	{
		if (res * res >= nb)
		{
			return (res);
		}
		++res;
	}
	if (res * res == nb)
		return (res);
	return (0);
}

int		countfig(t_list *figures)
{
	t_list	*nxt;
	int		count;

	count = 1;
	nxt = figures;
	while (nxt->next != NULL)
	{
		nxt = nxt->next;
		count++;
	}
	return (count);
}

t_map	*createmap(int size)
{
	t_map	*new;
	char	**arr;
	int		i;

	i = 0;
	new = (t_map *)malloc(sizeof(*new));
	arr = (char **)malloc(size * sizeof(char *));
	while (i < size)
	{
		arr[i] = ft_strnew(size);
		arr[i] = ft_memset(arr[i], '.', size);
		i++;
	}
	new->map = arr;
	new->size = size;
	return (new);
}

void	delmap(t_map **map)
{
	int		size;
	char	**mp;
	int		i;

	i = 0;
	size = (*map)->size;
	mp = (*map)->map;
	while (i < size)
	{
		free(mp[i]);
		mp[i] = NULL;
		i++;
	}
	free(mp);
	mp = NULL;
	free(*map);
	*map = NULL;
}

t_map	*mapresize(int size, t_map **mapold)
{
	t_map	*newmap;

	delmap(mapold);
	newmap = createmap(size + 1);
	return (newmap);
}
