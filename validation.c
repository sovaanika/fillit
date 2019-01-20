/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:31:04 by bbear             #+#    #+#             */
/*   Updated: 2019/01/20 02:59:29 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*validation(int fd)
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
		buff[res[0]] = '\0';
		val = check_val(buff);
		if (check_figure(buff))
			createoraddlist(&figures, buff, count);
		else
			ft_error();
		ft_bzero(buff, 21);
		count++;
		res[1] = res[0];
	}
	if ((res[0] <= 0 && res[1] != 20) || count > 25)
		ft_error();
	return (figures);
}
