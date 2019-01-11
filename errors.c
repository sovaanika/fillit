/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:06:27 by bbear             #+#    #+#             */
/*   Updated: 2019/01/10 19:06:54 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void		ft_usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl("./fillit source_file");
}
