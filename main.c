/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:12:57 by bbear             #+#    #+#             */
/*   Updated: 2019/01/10 18:22:22 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		res;
	int		fd;

	if (argc != 2)
	{
		ft_usage(argv[0]);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	res = f1(fd);
	if (res == -1)
	{
		ft_error();
		return (-1);
	}
	return (0);
}
