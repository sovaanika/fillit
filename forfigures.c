/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forfigures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:17:06 by bbear             #+#    #+#             */
/*   Updated: 2019/01/11 17:05:05 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		setpoint(int x, int y)
{
	t_point	result;

	result.x = x;
	result.y = y;
	return (result);
}

t_figure	*createfigure(char *buff, int count)
{
	t_figure	*result;
	char		**bu;
	int			cord[3];

	bu = ft_strsplit(buff, '\n');
	result = (t_figure*)malloc(sizeof(t_figure));
	cord[0] = 0;
	cord[2] = 0;
	while (cord[0] < 4)
	{
		cord[1] = 0;
		while (cord[1] < 4)
		{
			if (bu[cord[0]][cord[1]] == '#')
			{
				result->coordinates[cord[2]] = setpoint(cord[1], cord[0]);
				result->letter = 'A' + count;
				cord[2]++;
			}
			cord[1]++;
		}
		cord[0]++;
	}
	return (result);
}

t_figure	*leftup(t_figure *res)
{
	int			count;
	int			xmin;
	int			ymin;

	count = 0;
	xmin = 3;
	ymin = 3;
	while (count < 4)
	{
		if (xmin > res->coordinates[count].x)
			xmin = res->coordinates[count].x;
		if (ymin > res->coordinates[count].y)
			ymin = res->coordinates[count].y;
		count++;
	}
	count = 0;
	while (count < 4)
	{
		res->coordinates[count].x = res->coordinates[count].x - xmin;
		res->coordinates[count].y = res->coordinates[count].y - ymin;
		count++;
	}
	return (res);
}

t_list		*findend(t_list *figures)
{
	t_list	*nxt;

	nxt = figures;
	while (nxt->next != NULL)
		nxt = nxt->next;
	return (nxt);
}

void		createoraddlist(t_list **figures, char *buff, int count)
{
	t_list	*nxt;

	nxt = *figures;
	if (nxt == NULL)
		*figures = ft_lstnew(leftup(createfigure(buff, count)),
		sizeof(t_figure));
	else
	{
		nxt = findend(nxt);
		nxt->next = ft_lstnew(leftup(createfigure(buff, count)),
		sizeof(t_figure));
	}
}
