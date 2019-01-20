/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:12:57 by bbear             #+#    #+#             */
/*   Updated: 2019/01/20 02:59:56 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_usage(argv[0]);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	solution(validation(fd));
	return (0);
}
