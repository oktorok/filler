/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_addrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:41:02 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/07 16:40:51 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_get_addrs(void *img, int sizeline)
{
	int bits;
	int endian;

	bits = BITS;
	endian = ENDIAN;
	return (mlx_get_data_addr(img, &sizeline, &bits, &endian));
}
