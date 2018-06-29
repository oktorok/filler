/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:36:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/30 18:47:30 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		print_solution(t_data *data, int mp, int pp)
{
	int pos;

	pos = mp + (-(pp / data->piece_width) * data->map_width)
				- (pp % data->piece_width);
	ft_printf("%d %d\n", pos / data->map_width, pos % data->map_width);
	return (1);
}
