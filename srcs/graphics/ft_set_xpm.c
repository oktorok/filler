/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:01:47 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/04 23:21:10 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_img	*ft_set_xpm(t_mlx *mlx, char *file)
{
	t_img *new;

	if (!file)
		return (NULL);
	if (!(new = (t_img *)malloc(sizeof(t_img))))
		ft_error(NULL);
	new->data = mlx_xpm_file_to_image(mlx->ptr, file,
			&(new->width), &(new->height));
	return (new);
}
