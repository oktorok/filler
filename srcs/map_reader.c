/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:58:02 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/07 18:29:21 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_mapel		*ini_mapel(int map_width, int map_height)
{
	t_mapel *aux;
	int		i;
	int		size;

	size = map_width * map_height;
	if (!(aux = (t_mapel *)malloc(sizeof(t_mapel) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		aux[i].is_x = 0;
		aux[i].is_o = 0;
		aux[i].is_last = 0;
		i++;
	}
	return (aux);
}

static int			read_map(t_data *data)
{
	int		i;
	char	*buff;

	if (get_next_line(data->fd, &buff) < 0)
		return (0);
	free(buff);
	i = 0;
	while (i < data->map_height)
	{
		if (get_next_line(data->fd, &buff) < 0)
			return (0);
		update_map(data, i, buff);
		free(buff);
		i++;
	}
	return (1);
}

static int			read_piece(t_data *data)
{
	int		i;
	char	*buff;

	i = 0;
	while (i < data->piece_height)
	{
		if (get_next_line(data->fd, &buff) < 0)
			return (0);
		update_piece(data, i, buff);
		free(buff);
		i++;
	}
	return (1);
}

static void			allocate_map(t_data *data, char *buff)
{
	data->map_height = ft_atoi(buff + 8);
	data->map_width = ft_atoi(buff + 8 + ft_ndigits(data->map_height));
	if (!(data->map = ini_mapel(data->map_width, data->map_height)))
		ft_error(NULL);
}

int					map_reader(t_data *data)
{
	char	*buff;

	if (get_next_line(data->fd, &buff) < 0)
		return (0);
	if (!buff)
		return (2);
	if (!data->map_width || !data->map_height)
		allocate_map(data, buff);
	free(buff);
	if (!read_map(data))
		return (0);
	if ((get_next_line(data->fd, &buff)) < 0)
		return (0);
	data->piece_height = ft_atoi(buff + 6);
	data->piece_width = ft_atoi(buff + 6 + ft_ndigits(data->piece_height));
	free(buff);
	ft_memdel((void **)&data->piece);
	if (!(data->piece = (char *)ft_memalloc(sizeof(char) *
		ft_roundup((double)(data->piece_width * data->piece_height) / 8.0))))
		ft_error(NULL);
	if (!read_piece(data))
		return (0);
	return (1);
}

/*
** to see the read piece
** 	int i = 0;
**	write_test("\n");
**	while (i < (data->piece_width * data->piece_height))
**	{
**		if (data->piece[i / 8] & (0x80 >> (i % 8)))
**			write_test("*");
**		else
**			write_test(".");
**		if ((i % data->piece_width) == (data->piece_width - 1))
**			write_test("\n");
**		i++;
**	}
*/
