/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:59:58 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/07 17:47:27 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		search_ini_point(t_data *data)
{
	int i;

	i = 0;
	data->last_piece_width = 1;
	data->last_piece_height = 1;
	while (i < (data->map_width * data->map_height))
	{
		if (data->player ? data->map[i].is_x : data->map[i].is_o)
		{
			data->last_piece_mp = i;
			return ;
		}
		i++;
	}
}

/*
** to search by cuadrant (jump works better)
** static t_quad	search_quad(t_data *data)
** {
** 	int		i;
** 	t_quad	q;
**
** 	i = -1;
** 	q = (t_quad){0, data->map_width, data->map_height};
** 	while ((++i) < (data->map_width * data->map_height))
** 	{
** 		if (data->map[i].is_last)
** 		{
** 			if ((i % data->map_width) < (data->map_width / 2))
** 				q.quad_width = data->map_width / 2;
** 			else
** 				q.quad_start = data->map_width / 2;
** 			if ((i / data->map_height) < (data->map_height / 2))
** 				q.quad_height = data->map_height / 2;
** 			else
** 			{
** 				q.quad_height = data->map_height / 2;
** 				q.quad_start = q.quad_start +
** 				((data->map_height / 2) * data->map_width);
** 			}
** 			break ;
** 		}
** 	}
** 	return (q);
** }
*/

int				put_piece(t_data *data)
{
	int		mp;
	int		pp;

	mp = 0;
	pp = 0;
	if (!data->last_piece_width)
		search_ini_point(data);
	if (aproach_strat(data, &mp, &pp,
				(t_quad){0, data->map_width, data->map_height}))
	{
		data->last_piece_mp = mp;
		data->last_piece_pp = pp;
		return (print_solution(data, mp, pp));
	}
	else
		ft_printf("0 0\n");
	return (0);
}

/*
** mp = map point
** pp = piece point
*/
