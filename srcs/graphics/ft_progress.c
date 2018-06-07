/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:02:08 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/07 20:05:29 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static int	choose_color(int i, int p1)
{
	if (i < 10)
		return (!p1 ? 0x0273ff : 0x900272);
	else if (i < 20)
		return (!p1 ? 0x068bff : 0xaa0585);
	else if (i < 30)
		return (!p1 ? 0x0aa3ff : 0xc00999);
	else if (i < 70)
		return (!p1 ? 0x0fbcff : 0xda0ead);
	else if (i < 80)
		return (!p1 ? 0x0aa3ff : 0xc00999);
	else if (i < 90)
		return (!p1 ? 0x068bff : 0xaa0585);
	else
		return (!p1 ? 0x0273ff : 0x900272);
}

static void	p1_progress(int *addr, int width, int *lp)
{
	int		percent;
	int		i;
	int		j;

	i = 0;
	percent = (width * (lp[0] + 1)) / (lp[0] + lp[1] + 1);
	while (i < 100)
	{
		j = i * width;
		while (j < percent + i * width)
			addr[j++] = choose_color(i, 1);
		i++;
	}
	lp[0]++;
}

static void	p2_progress(int *addr, int width, int *lp)
{
	int		percent;
	int		i;
	int		j;

	i = 0;
	percent = width - (width * (lp[0] + 1)) / (lp[0] + lp[1] + 1);
	while (i < 100)
	{
		j = (width - 1) + (i * width);
		while (j > (width - percent + i * width))
			addr[j--] = choose_color(i, 0);
		i++;
	}
	lp[1]++;
}

void		ft_progress(t_mlx *mlx, int width, int p1)
{
	static int	lp[2] = {0, 0};
	int			*addr;

	addr = (int *)ft_get_addrs(mlx->info->progress, width);
	if (p1)
		p1_progress(addr, width, lp);
	else
		p2_progress(addr, width, lp);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->info->progress,
	MARGEN_X + mlx->map->map_pos[0], RESOLUTION_Y - MARGEN_Y - 100);
}
