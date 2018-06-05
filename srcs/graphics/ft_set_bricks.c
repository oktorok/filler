/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bricks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 01:31:17 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/05 03:18:08 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void		build_brick(t_mlx *mlx, int brick, int color)
{
	int	i;
	int	*addrs;

	i = 0;
	addrs = (int *)ft_get_addrs((mlx->map->bricks)[brick]->data,
									mlx->map->square[1] + 1);
	while (i < (mlx->map->square[1] + 1) * (mlx->map->square[0] + 1))
	{
		if (i <= (mlx->map->square[1] + 1) * 2)
			addrs[i] = 0;
		else if (i % (mlx->map->square[1] + 1) < 2 || i % (mlx->map->square[1]
				+ 1) > (mlx->map->square[1] + 1) - 3)
			addrs[i] = 0;
		else if (i > (mlx->map->square[1] + 1) * (mlx->map->square[0] - 1))
			addrs[i] = 0;
		else
			addrs[i] = color;
		i++;
	}
}

static void		set_color_as_brick(t_mlx *mlx, int color0, int color1)
{
	if (!(mlx->map->bricks[0] = (t_img *)ft_memalloc(sizeof(t_img))))
		ft_error(NULL);
	mlx->map->bricks[0]->data = mlx_new_image(mlx->ptr, mlx->map->square[1] + 1,
			mlx->map->square[0] + 1);
	build_brick(mlx, 0, color0);
	if (!(mlx->map->bricks[1] = (t_img *)ft_memalloc(sizeof(t_img))))
		ft_error(NULL);
	mlx->map->bricks[1]->data = mlx_new_image(mlx->ptr, mlx->map->square[1] + 1,
			mlx->map->square[0] + 1);
	build_brick(mlx, 1, color1);
}

static void		set_wipe_brick(t_mlx *mlx)
{
	int	i;
	int	*addrs;

	if (!(mlx->map->bricks[2] = (t_img *)ft_memalloc(sizeof(t_img))))
		ft_error(NULL);
	mlx->map->bricks[2]->data = mlx_new_image(mlx->ptr, mlx->map->square[1] + 1,
			mlx->map->square[0] + 1);
	addrs = (int *)ft_get_addrs(mlx->map->bricks[2]->data, mlx->map->square[1]);
	i = 0;
	while (i < (mlx->map->square[1] + 1) * (mlx->map->square[0] + 1))
		addrs[i++] = 0xFFFFFF;
}

void			ft_set_bricks(t_mlx *mlx)
{
	if (mlx->map->dim[0] == 15 && mlx->map->dim[1] == 17 && !COLOR_ALWAYS)
	{
		(mlx->map->bricks)[0] = ft_set_xpm(mlx, BRICK_PLAYER_ONE_1517);
		(mlx->map->bricks)[1] = ft_set_xpm(mlx, BRICK_PLAYER_TWO_1517);
	}
	else if (mlx->map->dim[0] == 24 && mlx->map->dim[1] == 40 && !COLOR_ALWAYS)
	{
		(mlx->map->bricks)[0] = ft_set_xpm(mlx, BRICK_PLAYER_ONE_2440);
		(mlx->map->bricks)[1] = ft_set_xpm(mlx, BRICK_PLAYER_TWO_2440);
	}
	else if (mlx->map->dim[0] == 100 && mlx->map->dim[1] == 99 && !COLOR_ALWAYS)
	{
		(mlx->map->bricks)[0] = ft_set_xpm(mlx, BRICK_PLAYER_ONE_10099);
		(mlx->map->bricks)[1] = ft_set_xpm(mlx, BRICK_PLAYER_TWO_10099);
	}
	else
		set_color_as_brick(mlx, COLOR_BRICK_PLAYER_ONE, COLOR_BRICK_PLAYER_TWO);
	set_wipe_brick(mlx);
}
