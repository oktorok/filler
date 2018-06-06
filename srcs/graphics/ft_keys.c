/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:01:10 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/06 02:40:47 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void		destroy_all(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->map->bricks[0]->data);
	mlx_destroy_image(mlx->ptr, mlx->map->bricks[1]->data);
	mlx_destroy_image(mlx->ptr, mlx->map->bricks[2]->data);
	free(mlx->map->bricks[0]);
	free(mlx->map->bricks[1]);
	free(mlx->map->bricks[2]);
	free(mlx->map->bricks);
	mlx_destroy_image(mlx->ptr, mlx->map->wallpaper->data);
	free(mlx->map->wallpaper);
	free(mlx->map);
	mlx_destroy_image(mlx->ptr, mlx->info->points_img[0]);
	mlx_destroy_image(mlx->ptr, mlx->info->points_img[1]);
	free(mlx->info->points_img);
	mlx_destroy_image(mlx->ptr, mlx->info->progress);
	mlx_destroy_image(mlx->ptr, mlx->info->img_pause->data);
	free(mlx->info->img_pause);
	free(mlx->info->players[0]);
	free(mlx->info->players[1]);
	free(mlx->info->players);
	free(mlx->info);
	free(mlx->piece[0]->shape);
	free(mlx->piece[1]->shape);
	free(mlx->piece[0]);
	free(mlx->piece[1]);
	free(mlx->piece);
}

static void		hide_pause(t_mlx *mlx)
{
	void	*img;
	int		*addrs_info;
	int		*addrs_wall;
	int		i;
	int		j;

	img = mlx_new_image(mlx->ptr, mlx->info->img_pause->width,
			mlx->info->img_pause->height);
	addrs_info = (int *)ft_get_addrs(img, mlx->info->img_pause->width);
	addrs_wall = (int *)ft_get_addrs(mlx->map->wallpaper->data,
			mlx->map->wallpaper->width);
	i = 0;
	j = RESOLUTION_X * (MARGEN_Y + 90) + RESOLUTION_X / 2 -
			mlx->info->img_pause->width;
	while (i < mlx->info->img_pause->width * mlx->info->img_pause->height)
	{
		addrs_info[i++] = addrs_wall[j];
		if (!(i % (mlx->info->img_pause->width)) && i)
			j += RESOLUTION_X - mlx->info->img_pause->width + 1;
		else
			j++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, img,
			RESOLUTION_X / 2 - mlx->info->img_pause->width / 2, MARGEN_Y + 90);
	mlx_destroy_image(mlx->ptr, img);
}

int				ft_keys(int code, void *mlx)
{
	t_mlx	*mmlx;

	if (code == ESC)
	{
		destroy_all(mlx);
		system("killall *filler* 2> /dev/null");
		exit(0);
	}
	else if (code == SPACE)
	{
		mmlx = (t_mlx *)mlx;
		mlx_put_image_to_window(mmlx->ptr, mmlx->win, mmlx->info->img_pause->
	data, RESOLUTION_X / 2 - mmlx->info->img_pause->width / 2, MARGEN_Y + 90);
		if (mmlx->info->pause)
		{
			mmlx->info->pause = 0;
			hide_pause(mlx);
		}
		else
			mmlx->info->pause = 1;
	}
	return (0);
}
