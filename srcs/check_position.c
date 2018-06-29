/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:23:15 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/07 18:26:08 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	check_limits(t_data *data, int mp, int pp)
{
	int piece_file;
	int map_file;
	int	piece_col;
	int	map_col;

	piece_file = pp / data->piece_width;
	map_file = mp / data->map_width;
	piece_col = pp % data->piece_width;
	map_col = mp % data->map_width;
	if ((map_file - piece_file) < 0)
		return (1);
	else if (map_file + (data->piece_height - piece_file - 1)
							>= data->map_height)
		return (1);
	else if ((map_col - piece_col) < 0)
		return (1);
	else if (map_col + (data->piece_width - piece_col - 1) >= data->map_width)
		return (1);
	return (0);
}

/*
**  for better vision:
**	int j_file;
**	int pp_file;
**	int j_col;
**	int pp_col;
**
**	j_file = (j / data->piece_width);
**	pp_file = (pp / data->piece_width);
**	j_col = j % data->piece_width;
**	pp_col = pp % data->piece_width;
**	pos = i + ((j_file - pp_file) * data->map_width) + (j_col - pp_col);
*/

static int	check_corners_p1(t_data *data, int pos)
{
	if ((pos % data->map_width) && (pos / data->map_width) &&
		data->map[(pos - 1 - data->map_width)].is_o && data->map[pos - 1].is_x
		&& data->map[pos - data->map_width].is_x)
		return (1);
	if ((pos % data->map_width) < (data->map_width - 1) &&
		(pos / data->map_width) && data->map[(pos + 1 - data->map_width)].is_o
		&& data->map[pos + 1].is_x && data->map[pos - data->map_width].is_x)
		return (1);
	if ((pos % data->map_width) < (data->map_width - 1) &&
		(pos / data->map_width) < (data->map_height - 1) &&
		data->map[(pos + 1 + data->map_width)].is_o && data->map[pos + 1].is_x
		&& data->map[pos + data->map_width].is_x)
		return (1);
	if ((pos % data->map_width) &&
		(pos / data->map_width) < (data->map_height - 1) &&
		data->map[(pos - 1 + data->map_width)].is_o && data->map[pos - 1].is_x
		&& data->map[pos + data->map_width].is_x)
		return (1);
	return (0);
}

static int	check_corners_p2(t_data *data, int pos)
{
	if ((pos % data->map_width) && (pos / data->map_width) &&
		data->map[(pos - 1 - data->map_width)].is_x && data->map[pos - 1].is_o
		&& data->map[pos - data->map_width].is_o)
		return (1);
	if ((pos % data->map_width) < (data->map_width - 1) &&
		(pos / data->map_width) && data->map[(pos + 1 - data->map_width)].is_x
		&& data->map[pos + 1].is_o && data->map[pos - data->map_width].is_o)
		return (1);
	if ((pos % data->map_width) < (data->map_width - 1) &&
		(pos / data->map_width) < (data->map_height - 1) &&
		data->map[(pos + 1 + data->map_width)].is_x && data->map[pos + 1].is_o
		&& data->map[pos + data->map_width].is_o)
		return (1);
	if ((pos % data->map_width) &&
		(pos / data->map_width) < (data->map_height - 1) &&
		data->map[(pos - 1 + data->map_width)].is_x && data->map[pos - 1].is_o
		&& data->map[pos + data->map_width].is_o)
		return (1);
	return (0);
}

static int	check_overlap(t_data *data, int pos, int *r_val)
{
	if (data->map[pos].is_x || data->map[pos].is_o)
		return (1);
	if (*r_val != 2)
	{
		if (data->player && check_corners_p2(data, pos))
			*r_val = 2;
		else if (check_corners_p1(data, pos))
			*r_val = 2;
	}
	return (0);
}

int			check_position(t_data *data, int mp, int pp)
{
	int j;
	int r_val;

	r_val = 1;
	if (check_limits(data, mp, pp))
		return (0);
	j = pp + 1;
	while (j < (data->piece_width * data->piece_height))
	{
		if (data->piece[j / 8] & (0x80 >> (j % 8)) && check_overlap(data,
			cord_piece_to_map(data->piece_width, data->map_width,
			(t_piece_point){mp, pp, j}), &r_val))
			return (0);
		j++;
	}
	j = pp - 1;
	while (j >= 0)
	{
		if (data->piece[j / 8] & (0x80 >> (j % 8)) && check_overlap(data,
			cord_piece_to_map(data->piece_width, data->map_width,
			(t_piece_point){mp, pp, j}), &r_val))
			return (0);
		j--;
	}
	return (r_val);
}

/*
** if r_val is 2, the piece can jump
** if r_val is 1, yhe piece is just fine
*/
