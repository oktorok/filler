/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:43:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/05 02:25:45 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		put_element(t_mlx *mlx, int i, int j, int piece_dim[2])
{
	int		aux;

	aux = ((i * piece_dim[1]) + j) / 8;
	mlx->piece[0]->shape[aux] = mlx->piece[0]->shape[aux] |
		(0x80 >> (((i * piece_dim[1]) + j) % 8));
}

static char		*set_line(int size)
{
	int		flag;
	char	*line;
	char	*tmp;

	tmp = NULL;
	while (1)
	{
		line = ft_strnew(size + 1);
		if ((flag = read(STDIN_FILENO, line, size + 1 - ft_strlen(tmp))) < 0)
			ft_error(NULL);
		if (!flag)
			ft_error("ERROR There is no piece\n");
		if (tmp)
			line = ft_strjoinfree(tmp, line);
		if ((int)ft_strlen(line) != (size + 1))
		{
			tmp = ft_strdup(line);
			free(line);
		}
		else
			break ;
	}
	return (line);
}

void			ft_get_piece(t_mlx *mlx, int piece_dim[2])
{
	int		j;
	int		i;
	char	*line;

	i = 0;
	while (i < piece_dim[0])
	{
		line = set_line(piece_dim[1]);
		line[piece_dim[1]] = 0;
		j = 0;
		while (j < piece_dim[1])
		{
			if (line[j] == '*')
				put_element(mlx, i, j, piece_dim);
			j++;
		}
		free(line);
		i++;
	}
}
