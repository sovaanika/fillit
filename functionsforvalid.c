/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsforvalid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:33:58 by bbear             #+#    #+#             */
/*   Updated: 2019/01/16 18:22:55 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_newline(char *buff)
{
	int	res;

	res = 0;
	buff[4] == '\n' ? res++ : 0;
	buff[9] == '\n' ? res++ : 0;
	buff[14] == '\n' ? res++ : 0;
	buff[19] == '\n' ? res++ : 0;
	if (buff[20] == '\n' || buff[20] == '\0')
		res++;
	if (res != 5)
		ft_error();
}

int		check_map(char *buff)
{
	int		chk_d;
	int		flag;

	chk_d = 0;
	flag = 0;
	check_newline(buff);
	while (*buff && flag < 2)
	{
		if (*buff == '.')
			chk_d++;
		if (*buff == '\n')
		{
			flag++;
			buff++;
			if (*buff == '\n')
				flag++;
			else
				flag--;
		}
		else
			buff++;
	}
	if (chk_d != 12)
		ft_error();
	return (1);
}

int		check_figure(char *buff)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			if (i - 5 > -1)
				buff[i - 5] == '#' ? count++ : 0;
			if (i + 5 < 19)
				buff[i + 5] == '#' ? count++ : 0;
			if (i != 0 && i != 5 && i != 10 && i != 15)
				buff[i - 1] == '#' ? count++ : 0;
			if (i != 3 && i != 8 && i != 13 && i != 18)
				buff[i + 1] == '#' ? count++ : 0;
		}
		i++;
	}
	return (count == 6 || count == 8 ? 1 : 0);
}

int		check_val(char *buff)
{
	int		mapcorr;

	mapcorr = check_map(buff);
	if (ft_strlen(buff) != 20 && ft_strlen(buff) != 21)
		ft_error();
	else if (ft_strlen > 0 && mapcorr)
		return (1);
	return (0);
}
