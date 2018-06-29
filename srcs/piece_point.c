/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:27:20 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/04 17:35:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		piece_point(t_data *data)
{
	int pp;
	int i;

	i = 0;
	while (i < (data->piece_height * data->piece_width))
	{
		if (data->piece[i / 8] & 0x80 >> (i % 8))
			pp = i;
		i++;
	}
	return (pp);
}
