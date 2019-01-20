/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:11:51 by bbear             #+#    #+#             */
/*   Updated: 2019/01/20 02:59:15 by bbear            ###   ########.fr       */
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

typedef struct		s_map
{
	int				size;
	char			**map;
}					t_map;

t_point				setpoint(int x, int y);
int					ft_check_len(char *buff);
int					check_map(char *buff);
int					check_figure(char *buff);
int					check_val(char *buff);
void				check_newline(char *buff);
t_list				*validation(int fd);
void				ft_error(void);
void				ft_usage(char *name);
t_figure			*createfigure(char *buff, int count);
t_list				*findend(t_list *figures);
void				createoraddlist(t_list **figures, char *buff, int count);
t_figure			*leftup(t_figure *res);
void				solution(t_list *figures);
t_map				*createmap(int size);
int					countfig(t_list *figures);
int					ft_sqrt(int nb);
void				delmap(t_map **map);
t_map				*mapresize(t_map **mapold);
int					puttmap(t_map **map, t_figure *figure, int *cord);
void				delfig(t_map **map, t_figure *figure);
int					recursion(t_map **map, t_list *figures);

#endif
