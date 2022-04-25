/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:41:57 by akhouya           #+#    #+#             */
/*   Updated: 2022/04/25 02:07:45 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	code_key_w(t_solong *attri)
{
	if (attri->map[attri->p_x - 1][attri->p_y] == 'C')
			attri->count_coin--;
	if (attri->count_coin == 0 && attri->map[attri->p_x - 1][attri->p_y] == 'E')
	{
		attri->movement++;
		printf("number of movements: %d\n", attri->movement);
		frealltab(attri->map);
		free(attri->map);
		exit(0);
	}
	if (attri->map[attri->p_x - 1][attri->p_y] != 'E')
	{
		mlx_clear_window(attri->mlx, attri->win);
		attri->p_x--;
		attri->movement++;
		printf("number of movements: %d\n", attri->movement);
		parse_ma_drawingg(attri);
	}
}

void	code_key_s(t_solong *attri)
{
	if (attri->map[attri->p_x + 1][attri->p_y] == 'C')
			attri->count_coin--;
	if (attri->count_coin == 0 && attri->map[attri->p_x + 1][attri->p_y] == 'E')
	{
		attri->movement++;
		printf("number of movements: %d\n", attri->movement);
		frealltab(attri->map);
		free(attri->map);
		exit(0);
	}
	if (attri->map[attri->p_x + 1][attri->p_y] != 'E')
	{
		mlx_clear_window(attri->mlx, attri->win);
		attri->p_x++;
		attri->movement++;
		printf("number of movements: %d\n", attri->movement);
		parse_ma_drawingg(attri);
	}
}

void	code_key_a(t_solong *attri)
{
	if (attri->map[attri->p_x][attri->p_y - 1] == 'C')
		attri->count_coin--;
	if (attri->count_coin == 0 && attri->map[attri->p_x][attri->p_y - 1] == 'E')
	{
		attri->movement++;
		printf("number of movements: %d\n", attri->movement);
		frealltab(attri->map);
		free(attri->map);
		exit(0);
	}
	if (attri->map[attri->p_x][attri->p_y - 1] != 'E')
	{
		mlx_clear_window(attri->mlx, attri->win);
		attri->p_y--;
		attri->movement++;
		printf("number of movements: %d\n", attri->movement);
		parse_ma_drawingg(attri);
	}
}

void	code_key_d(t_solong *attri)
{
	if (attri->map[attri->p_x][attri->p_y + 1] == 'C')
			attri->count_coin--;
	if (attri->count_coin == 0 && attri->map[attri->p_x][attri->p_y + 1] == 'E')
	{
		attri->movement++;
		printf("number of movements: %d\n", attri->movement);
		frealltab(attri->map);
		free(attri->map);
		exit(0);
	}
	if (attri->map[attri->p_x][attri->p_y + 1] != 'E')
	{
		mlx_clear_window(attri->mlx, attri->win);
		attri->p_y++;
		attri->movement++;
		printf("number of movements: %d\n", attri->movement);
		parse_ma_drawingg(attri);
	}
}

int	mlx_move(int codekey, void *param)
{
	t_solong	*attri;

	attri = (t_solong *) param;
	if (codekey == 13 && attri->map[attri->p_x - 1][attri->p_y] != '1')
		code_key_w(attri);
	else if (codekey == 1 && attri->map[attri->p_x + 1][attri->p_y] != '1')
		code_key_s(attri);
	else if (codekey == 0 && attri->map[attri->p_x][attri->p_y - 1] != '1')
		code_key_a(attri);
	else if (codekey == 2 && attri->map[attri->p_x][attri->p_y + 1] != '1')
		code_key_d(attri);
	else if (codekey == 49)
	{
		frealltab(attri->map);
		free(attri->map);
		exit(0);
	}
	return (0);
}
