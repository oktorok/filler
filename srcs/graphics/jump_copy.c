/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:31:17 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/04 04:50:00 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static int		size_piece(t_piece *piece)
{
	return ((piece->dim[0] * piece->dim[1]) / 8 +
			((piece->dim[0] * piece->dim[1]) % 8 ? 1 : 0));
}

void			ft_jump_map(int dim[2])
{
	int map;

	map = (dim[0] + 1) * (dim[1] + 5);
	if (dim[0] > 1000)
		map += dim[0] - 1000;
	ft_seek(STDIN_FILENO, map);
}

void			ft_copy_piece(t_mlx *mlx)
{
	mlx->piece[1]->dim[0] = mlx->piece[0]->dim[0];
	mlx->piece[1]->dim[1] = mlx->piece[0]->dim[1];
	mlx->piece[1]->pos[0] = mlx->piece[0]->pos[0];
	mlx->piece[1]->pos[1] = mlx->piece[0]->pos[1];
	mlx->piece[1]->player = mlx->piece[0]->player;
	ft_strdel(&(mlx->piece[1]->shape));
	mlx->piece[1]->shape = ft_strnew(size_piece(mlx->piece[1]));
	ft_memcpy(mlx->piece[1]->shape, mlx->piece[0]->shape,
				size_piece(mlx->piece[1]));
}

int				ft_jump_piece(t_mlx *mlx)
{
	int		a;
	char	*line;

	if ((a = get_next_line(STDIN_FILENO, &line)) < 0)
		ft_error(NULL);
	else if (!a)
		ft_error("ERROR no estan las dimensiones\n");
	if (*(line + 1) == 'l')
	{
		free(line);
		return (0);
	}
	if (*line == '=')
	{
		free(line);
		return (-1);
	}
	mlx->piece[0]->dim[0] = ft_atoi(ft_strchr(line, ' ') + 1);
	mlx->piece[0]->dim[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
	free(line);
	ft_strdel(&(mlx->piece[0]->shape));
	mlx->piece[0]->shape = ft_strnew(size_piece(mlx->piece[0]));
	ft_get_piece(mlx, mlx->piece[0]->dim);
	return (1);
}
