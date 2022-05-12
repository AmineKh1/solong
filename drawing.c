/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 02:08:34 by akhouya           #+#    #+#             */
/*   Updated: 2022/05/12 12:57:47 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void static	protect(t_solong *attribut)
{
	if (attribut->imgnori == NULL || attribut->imgplayer == NULL
		||attribut->imgport == NULL || attribut->imgwall == NULL
		|| attribut->win == NULL)
		exit(1);
}

void	parse_ma_drawing(t_solong *attribut)
{
	int	i;

	i = 0;
	attribut->imgwall = mlx_xpm_file_to_image(attribut->mlx,
			"wall.xpm", &attribut->img_w, &attribut->img_h);
	attribut->imgnori = mlx_xpm_file_to_image(attribut->mlx,
			"poudre.xpm", &attribut->img_w, &attribut->img_h);
	attribut->imgplayer = mlx_xpm_file_to_image(attribut->mlx,
			"nonos.xpm", &attribut->img_w, &attribut->img_h);
	attribut->imgport = mlx_xpm_file_to_image(attribut->mlx,
			"port.xpm", &attribut->img_w, &attribut->img_h);
	attribut->win = mlx_new_window(attribut->mlx,
			64 * attribut->lent.y, 64 * attribut->lent.x, "solong");
	mlx_put_image_to_window(attribut->mlx, attribut->win,
		attribut->imgplayer, attribut->p_y * 64, attribut->p_x * 64);
	protect(attribut);
	while (attribut->map[i])
	{
		check_byte_drawing(attribut, attribut->map[i], i, attribut->lent.y);
		i++;
	}
}

int	close_dstroy(void *param)
{
	t_solong	*test;

	test = (t_solong *) param;
	exit(0);
}
