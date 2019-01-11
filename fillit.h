/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:11:51 by bbear             #+#    #+#             */
/*   Updated: 2019/01/10 19:01:54 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_figure
{
	t_point			coordinates[4];
	char			letter;
}					t_figure;

t_point				setpoint(int x, int y);
int					ft_check_len(char *buff);
int					check_map(char *buff);
int					check_figure(char *buff);
int					check_val(char *buff);
int					f1(int fd);
void				ft_error(void);
void				ft_usage(char *name);
t_figure			*createfigure(char *buff, int count);
t_list				*findend(t_list *figures);
void				createoraddlist(t_list **figures, char *buff, int count);

#endif
