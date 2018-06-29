/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_piece_to_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:01:22 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/30 18:35:08 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		cord_piece_to_map(int p_width, int m_width, t_piece_point piec)
{
	return (piec.mp + (((piec.p / p_width) - (piec.pp / p_width)) * m_width)
			+ ((piec.p % p_width) - (piec.pp % p_width)));
}
