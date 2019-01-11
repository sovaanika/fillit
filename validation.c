/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:31:04 by bbear             #+#    #+#             */
/*   Updated: 2019/01/10 19:07:11 by bbear            ###   ########.fr       */
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

t_list		*findend(t_list *figures)
{
	t_list *nxt;

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
		*figures = ft_lstnew(createfigure(buff, count), sizeof(t_figure));
	else
	{
		nxt = findend(nxt);
		nxt->next = ft_lstnew(createfigure(buff, count), sizeof(t_figure));
	}
}

int			f1(int fd)
{
	char	buff[22];
	t_list	*figures;
	int		res[2];
	int		val;
	int		count;

	val = 2;
	count = 0;
	res[1] = 0;
	figures = NULL;
	while ((res[0] = read(fd, buff, 21)) > 0)
	{
		buff[21] = '\0';
		val = check_val(buff);
		if (check_figure(buff))
			createoraddlist(&figures, buff, count);
		else
			ft_error();
		ft_bzero(buff, 21);
		count++;
		res[1] = res[0];
	}
	if (res[0] == 0 && res[1] != 20)
		ft_error();
	return (0);
}

//gcc -g validation.c functionsforvalid.c main.c ./libft/libft.a -I./libft/
