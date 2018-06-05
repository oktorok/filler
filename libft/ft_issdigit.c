/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 02:54:46 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/06 03:04:42 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_issdigit(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!(ft_isdigit(*(str++))))
			return (0);
	}
	return (1);
}
