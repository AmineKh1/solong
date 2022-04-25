/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:04:21 by akhouya           #+#    #+#             */
/*   Updated: 2022/04/25 02:48:56 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	parse_ma_drawingg(t_solong *attribut)
{
	int	i;

	i = 0;
	attribut->map[attribut->p_x][attribut->p_y] = 'P';
	mlx_put_image_to_window(attribut->mlx, attribut->win, attribut->imgplayer,
		attribut->p_y * 64, attribut->p_x * 64);
	while (attribut->map[i])
	{
		check_byte_drawing(attribut, attribut->map[i], i, attribut->lent.y);
		i++;
	}
}

void	check_byte_drawing(t_solong *attribut, char *line, int i, int lent)
{
	int	j;

	j = -1;
	while (++j < lent)
	{
		if (line[j] == '1')
		{
			mlx_put_image_to_window(attribut->mlx, attribut->win,
				attribut->imgwall, j * 64, i * 64);
		}
		if (line[j] == 'C')
		{
			mlx_put_image_to_window(attribut->mlx, attribut->win,
				attribut->imgnori, j * 64, i * 64);
		}
		if (line[j] == 'E')
		{
			mlx_put_image_to_window(attribut->mlx, attribut->win,
				attribut->imgport, j * 64, i * 64);
		}
		if (line[j] == '0')
			continue ;
	}
}

int	init_ext(t_solong *attribut, char **argv, int argc)
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	attribut->map = NULL;
	attribut->p_x = -1;
	attribut->error = 0;
	attribut->count_coin = 0;
	attribut->exit = 0;
	attribut->movement = 0;
	attribut->fd = open (argv[1], O_RDWR);
	check_ext_map(argc, argv, attribut);
	s = get_next_line(attribut->fd);
	while (s != 0)
	{
		i++;
		free(s);
		s = get_next_line(attribut->fd);
	}
	free(s);
	close(attribut->fd);
	return (i);
}

int	main(int argc, char **argv)
{
	t_solong	attribut;
	int			i;

	i = init_ext(&attribut, argv, argc);
	attribut.map = malloc((i + 2) * sizeof(char *));
	attribut.fd = open (argv[1], O_RDWR);
	i = 0;
	attribut.map[i] = get_next_line(attribut.fd);
	while (attribut.map[i++] != 0)
		attribut.map[i] = get_next_line(attribut.fd);
	attribut.map[i] = NULL;
	close(attribut.fd);
	parse_map(&attribut);
	attribut.mlx = mlx_init();
	parse_ma_drawing(&attribut);
	mlx_hook(attribut.win, 2, 0, &mlx_move, &attribut);
	mlx_hook(attribut.win, 17, 0, &close_dstroy, &attribut);
	mlx_loop(attribut.mlx);
}
