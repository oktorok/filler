/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:14:12 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/29 07:32:05 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t			i;
	char			*s1;
	const char		*s2;

	s1 = str1;
	s2 = str2;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (str1);
}
