/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:23:15 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/30 18:43:56 by mrodrigu         ###   ########.fr       */
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

static int	check_overlap(t_data *data, int i, int pp, int j)
{
	int pos;

	pos = cord_piece_to_map(data->piece_width, data->map_width,
							(t_piece_point){i, pp, j});
	if (data->map[pos].is_x || data->map[pos].is_o)
		return (1);
	return (0);
}

int			check_position(t_data *data, int mp, int pp)
{
	int j;

	if (check_limits(data, mp, pp))
		return (0);
	j = pp + 1;
	while (j < (data->piece_width * data->piece_height))
	{
		if (data->piece[j / 8] & (0x80 >> (j % 8)))
		{
			if (check_overlap(data, mp, pp, j))
				return (0);
		}
		j++;
	}
	j = pp - 1;
	while (j >= 0)
	{
		if (data->piece[j / 8] & (0x80 >> (j % 8)))
		{
			if (check_overlap(data, mp, pp, j))
				return (0);
		}
		j--;
	}
	return (1);
}
