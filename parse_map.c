/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:29:22 by akhouya           #+#    #+#             */
/*   Updated: 2022/05/14 16:58:20 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_lent(char **map)
{
	int		i;
	size_t	lent;

	i = -1;
	lent = ft_strlen(map[i + 1]);
	while (map[++i])
	{
		if (map[i + 1] == NULL)
			lent--;
		if (ft_strlen(map[i]) != lent)
			return (-1);
	}
	return (lent - 1);
}

void	parse_map(t_solong *attribut)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	attribut->lent.y = check_lent(attribut->map);
	if (attribut->lent.y == -1)
		attribut->error = 1;
	while (attribut->map[++i])
	{
		if ((!i || !attribut->map[i + 1])
			&& check_map_1(attribut->map[i], attribut->lent.y))
			attribut->error = 1;
		check_byte(attribut, attribut->map[i], i, attribut->lent.y);
	}
	attribut->lent.x = i;
	attribut->lent.y++;
	if (attribut->exit < 1 || attribut->error == 1 || attribut->count_coin == 0)
	{
		frealltab(attribut->map);
		free(attribut->map);
		ft_printf("Error\nInvalid map\n");
		exit(1);
	}
}

int	check_map_1(char *s, int lent)
{
	int	j;

	j = 0;
	while (lent-- > 0)
	{
		if (s[lent] != '1')
			return (1);
	}
	return (0);
}

void	check_byte(t_solong *attribut, char *line, int i, int lent)
{
	int	j;

	j = -1;
	while (++j <= lent && attribut->error != 1)
	{
		if ((j == 0 || j == lent) && line[j] != '1')
			attribut->error = 1;
		else if (line[j] == 'C')
			attribut->count_coin++;
		else if (line[j] == 'E')
			attribut->exit = 1;
		else if (line[j] == 'P' && attribut->p_x == -1)
		{
			attribut->p_y = j;
			attribut->p_x = i;
		}
		else if (line[j] == '1' || line[j] == '0')
			continue ;
		else
			attribut->error = 1;
	}
}

void	check_ext_map(int argc, char **argv, t_solong *attribut)
{
	char	*s;

	s = NULL;
	if (argc != 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	s = ft_strrchr(argv[1], '.');
	condition_ext(attribut, s);
}
