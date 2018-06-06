/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:55:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/06 02:02:16 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "graphics.h"

typedef struct		s_mapel
{
	unsigned int	is_x : 1;
	unsigned int	is_o : 1;
	unsigned int	is_last : 1;
}					t_mapel;

typedef struct		s_data
{
	int				fd;
	int				map_width;
	int				map_height;
	int				piece_width;
	int				piece_height;
	int				player : 1;
	int				last_piece_pp;
	int				last_piece_mp;
	int				last_piece_width;
	int				last_piece_height;
	t_mapel			*map;
	char			*piece;
}					t_data;

typedef struct		s_quad
{
	int				quad_start;
	int				quad_width;
	int				quad_height;
}					t_quad;

typedef struct		s_aproach
{
	int				i;
	int				j;
	int				k;
	int				mp;
	int				pp;
	int				pos;
	int				diff;
	int				aux_diff;
}					t_aproach;

typedef struct		s_piece_point
{
	int				mp;
	int				pp;
	int				p;
}					t_piece_point;

void				ft_seek(int fd, int cuant);
int					map_reader(t_data *data);
int					ft_ndigits(int n);
void				update_map(t_data *data, int i, char *buff);
void				update_piece(t_data *data, int i, char *buff);
void				write_test(char *str);
int					ft_roundup(double d);
int					put_piece(t_data *data);
int					check_position(t_data *data, int i, int pp);
int					piece_point(t_data *data);
int					print_solution(t_data *data, int i, int pp);
int					cord_piece_to_map(int p_wih, int m_wih, t_piece_point pic);
int					aproach_strat(t_data *data, int *mp, int *pp, t_quad quad);

#endif
