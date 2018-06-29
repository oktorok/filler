/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/06 00:53:28 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void		finish_game(t_mlx *mlx)
{
	t_img	*img;

	if (mlx->info->puntuation[0] > mlx->info->puntuation[1])
		img = ft_set_xpm(mlx, PLAYER_ONE_WINS);
	else if (mlx->info->puntuation[0] < mlx->info->puntuation[1])
		img = ft_set_xpm(mlx, PLAYER_TWO_WINS);
	else
		img = ft_set_xpm(mlx, DRAW);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->data, RESOLUTION_X / 2 -
			img->width / 2, RESOLUTION_Y / 2 - img->height / 2);
}

static int		loop(void *mlx)
{
	static int	end = 1;

	if (end >= 0 && !(((t_mlx *)mlx)->info->pause))
	{
		ft_set_piece_pos(mlx);
		if (!(end = ft_jump_piece(mlx)))
		{
			ft_place_piece(mlx, 0, 3);
			if (((t_mlx *)mlx)->piece[1]->shape)
				ft_place_piece(mlx, 1, ((t_mlx *)mlx)->piece[1]->player);
			ft_copy_piece(mlx);
			ft_jump_map(((t_mlx *)mlx)->map->dim);
			ft_jump_piece(mlx);
		}
		else if (end < 0)
		{
			ft_place_piece(mlx, -1, ((t_mlx *)mlx)->piece[1]->player);
			finish_game(mlx);
		}
		else
			ft_place_piece(mlx, 1, ((t_mlx *)mlx)->piece[1]->player);
	}
	return (0);
}

int				main(void)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_error(NULL);
	if (!(mlx->ptr = mlx_init()))
		ft_error(NULL);
	if (!(mlx->win = mlx_new_window(mlx->ptr, RESOLUTION_X,
			RESOLUTION_Y, "FILLER")))
		ft_error(NULL);
	ft_initialice(mlx);
	ft_set_bricks(mlx);
	ft_print_map(mlx);
	ft_info(mlx);
	mlx_key_hook(mlx->win, ft_keys, mlx);
	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
