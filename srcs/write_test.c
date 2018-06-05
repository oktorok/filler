/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:01:39 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/30 18:59:27 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	write_test(char *str)
{
	int	fd;

	fd = open("datos.txt", O_RDWR | O_APPEND);
	write(fd, str, ft_strlen(str));
	close(fd);
}
