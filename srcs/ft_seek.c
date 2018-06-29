/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:09:54 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/04 23:29:30 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_seek(int fd, int cuant)
{
	char	*buff;
	int		flag;
	int		realcuant;

	realcuant = cuant;
	if (!(buff = (char *)ft_memalloc(sizeof(char) * (cuant + 1))))
		ft_error(NULL);
	while (cuant)
	{
		if ((flag = read(fd, buff, cuant)) < 0)
			ft_error(NULL);
		else if (!flag)
			return ;
		ft_bzero(buff, realcuant);
		cuant -= flag;
	}
	free(buff);
}
