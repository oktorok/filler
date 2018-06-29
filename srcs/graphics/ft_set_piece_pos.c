/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_piece_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:28:55 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/04 04:38:56 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void			ft_set_piece_pos(t_mlx *mlx)
{
	int		a;
	char	*line;

	a = get_next_line(STDIN_FILENO, &line);
	if (a < 0)
		ft_error(NULL);
	else if (!a)
		ft_error("ERROR no esta la posicion de la pieza\n");
	if (line[0] == '<')
	{
		mlx->piece[0]->player = *(ft_strchr(line, '(') + 1);
		mlx->piece[0]->pos[0] = ft_atoi(ft_strchr(line, '[') + 1);
		mlx->piece[0]->pos[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
	}
	free(line);
}
