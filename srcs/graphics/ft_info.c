/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 03:57:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/05 02:57:32 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void			ft_update_info(t_mlx *mlx, char player)
{
	char		*tmp;

	if (player == PLAYER_ONE)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->info->points_img[0], 0, RESOLUTION_Y - MARGEN_Y - 58);
		mlx_string_put(mlx->ptr, mlx->win, MARGEN_X - 50, RESOLUTION_Y -
						MARGEN_Y - 60,
			COLOR_PLAYER_ONE_NFO, (tmp = ft_itoa(mlx->info->puntuation[0]++)));
	}
	else
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->info->points_img[1], RESOLUTION_X - MARGEN_X,
			RESOLUTION_Y - MARGEN_Y - 58);
		mlx_string_put(mlx->ptr, mlx->win, RESOLUTION_X - MARGEN_X + 30,
			RESOLUTION_Y - MARGEN_Y - 60, COLOR_PLAYER_TWO_NFO,
			(tmp = ft_itoa(mlx->info->puntuation[1]++)));
	}
	free(tmp);
}

static void		paint_image(t_mlx *mlx, int img)
{
	int	*addrs_info;
	int	*addrs_wall;
	int	i;
	int j;

	addrs_info = (int *)ft_get_addrs(mlx->info->points_img[img], MARGEN_X);
	addrs_wall = (int *)ft_get_addrs(mlx->map->wallpaper->data,
			mlx->map->wallpaper->width);
	i = 0;
	j = RESOLUTION_X * (RESOLUTION_Y - MARGEN_Y - 28) - MARGEN_X * img;
	while (i < (MARGEN_X * 20))
	{
		addrs_info[i++] = addrs_wall[j];
		if (!(i % (MARGEN_X)) && i)
			j += RESOLUTION_X - MARGEN_X + 1;
		else
			j++;
	}
}

void			ft_info(t_mlx *mlx)
{
	if (!(mlx->info->progress = mlx_new_image(mlx->ptr,
			mlx->map->square[1] * mlx->map->dim[1], 100)))
		ft_error(NULL);
	mlx->info->points_img[0] = mlx_new_image(mlx->ptr, MARGEN_X, 20);
	mlx->info->points_img[1] = mlx_new_image(mlx->ptr, MARGEN_X, 20);
	paint_image(mlx, 0);
	paint_image(mlx, 1);
	mlx_string_put(mlx->ptr, mlx->win, 70, RESOLUTION_Y - MARGEN_Y - 150,
				COLOR_PLAYER_ONE_NFO, mlx->info->players[0]);
	mlx_string_put(mlx->ptr, mlx->win, MARGEN_X + 50, RESOLUTION_Y - MARGEN_Y
					- 60, COLOR_PLAYER_ONE_NFO, "0");
	mlx_string_put(mlx->ptr, mlx->win, RESOLUTION_X - MARGEN_X + 70,
				RESOLUTION_Y - MARGEN_Y - 150, COLOR_PLAYER_TWO_NFO,
				mlx->info->players[1]);
	mlx_string_put(mlx->ptr, mlx->win, RESOLUTION_X - MARGEN_X + 30,
				RESOLUTION_Y - MARGEN_Y - 60, COLOR_PLAYER_TWO_NFO, "0");
}
