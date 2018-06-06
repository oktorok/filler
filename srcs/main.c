/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:49:37 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/06 02:31:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** player with O = 0
** player with X = 1
*/

static int		ini_player(t_data *data)
{
	char	*buff;

	if (get_next_line(data->fd, &buff) < 0)
		return (1);
	data->player = ((buff[10] == '2') ? -1 : 0);
	write_test(buff);
	free(buff);
	return (0);
}

int				main(void)
{
	int		ret;
	t_data	data;

	data = (t_data){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL};
	if (ini_player(&data))
		return (0);
	while ((ret = map_reader(&data)))
	{
		if (ret == 1)
		{
			if (!put_piece(&data))
			{
				if (data.piece)
					free(data.piece);
				if (data.map)
					free(data.map);
				return (0);
			}
		}
	}
	if (data.piece)
		free(data.piece);
	if (data.map)
		free(data.map);
	return (0);
}
