/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aproach_strat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:00:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/07 17:54:28 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		is_front(t_data *data, int k)
{
	if (((k % data->map_width) && (data->map[k - 1].is_x ||
			data->map[k - 1].is_o)) && (((k % data->map_width) !=
			(data->map_width - 1)) && (data->map[k + 1].is_x ||
			data->map[k + 1].is_o)) && ((k / data->map_width) &&
			(data->map[k - data->map_width].is_x ||
			data->map[k - data->map_width].is_o)) && (((k / data->map_width) !=
			(data->map_height - 1)) && (data->map[k + data->map_width].is_x ||
			data->map[k + data->map_width].is_o)) &&
			(data->map[k - 1 - data->map_width].is_x ||
			data->map[k - 1 - data->map_width].is_o)
			&& (data->map[k + 1 - data->map_width].is_x ||
			data->map[k + 1 - data->map_width].is_o)
			&& (data->map[k + 1 + data->map_width].is_x ||
			data->map[k + 1 + data->map_width].is_o)
			&& (data->map[k - 1 + data->map_width].is_x ||
			data->map[k - 1 + data->map_width].is_o))
		return (0);
	return (1);
}

static int		check_enemy_points(t_data *data, int pos)
{
	int i;
	int diff;
	int aux_diff;

	i = 0;
	diff = data->map_width * data->map_height;
	while (i < (data->map_width * data->map_height))
	{
		if (data->player ? data->map[i].is_o : data->map[i].is_x)
		{
			if (is_front(data, i))
			{
				if ((aux_diff = abs(i / data->map_width - pos / data->map_width)
					+ abs(i % data->map_width - pos % data->map_width)) <= diff)
					diff = aux_diff;
			}
		}
		i++;
	}
	return (diff);
}

static int		check_piece_pos(t_data *data, t_aproach *apr, int r_cp)
{
	if (r_cp == 2)
	{
		apr->mp = apr->k;
		apr->pp = apr->i;
		return (1);
	}
	apr->j = 0;
	while (apr->j < (data->piece_width * data->piece_height))
	{
		if (data->piece[apr->j / 8] & (0x80 >> (apr->j % 8)))
		{
			apr->pos = cord_piece_to_map(data->piece_width, data->map_width,
									(t_piece_point){apr->k, apr->i, apr->j});
			if ((apr->aux_diff =
				check_enemy_points(data, apr->pos)) < apr->diff)
			{
				apr->diff = apr->aux_diff;
				apr->mp = apr->k;
				apr->pp = apr->i;
			}
		}
		apr->j++;
	}
	return (0);
}

static void		check_map(t_data *data, t_quad quad, t_aproach *apr)
{
	int r_cp;

	while (apr->k < (quad.quad_width * quad.quad_height))
	{
		apr->i = 0;
		if (data->player ? data->map[apr->k].is_x : data->map[apr->k].is_o)
		{
			if (is_front(data, apr->k))
			{
				while (apr->i < (data->piece_width * data->piece_height))
				{
					if (data->piece[apr->i / 8] & (0x80 >> (apr->i % 8)))
					{
						if ((r_cp = check_position(data, apr->k, apr->i)))
							if (check_piece_pos(data, apr, r_cp))
								return ;
					}
					apr->i++;
				}
			}
		}
		apr->k++;
		if ((apr->k % data->map_width) >= quad.quad_width)
			apr->k = apr->k + (data->map_width - quad.quad_width);
	}
}

int				aproach_strat(t_data *data, int *mp, int *pp, t_quad quad)
{
	t_aproach	apr;

	apr = (t_aproach){0, 0, quad.quad_start, 0, 0, 0,
						data->map_width * data->map_height, 0};
	check_map(data, quad, &apr);
	*mp = apr.mp;
	*pp = apr.pp;
	if (apr.diff == data->map_width * data->map_height)
		return (0);
	return (apr.diff);
}
