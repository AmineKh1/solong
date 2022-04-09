/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:04:21 by akhouya           #+#    #+#             */
/*   Updated: 2022/04/09 03:09:29 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include<string.h>

void	check_ext_map(int argc, char **argv, t_solong *attribut)
{
	char **str;
	if (argc != 2)
		exit(1);
	str = ft_split(argv[1], '.');
	if(ft_strncmp(str[1], "ber", 4) != 0)
	{
		frealltab(str);
		free(str);
		system("leaks a.out");
		exit(1);
	}
	frealltab(str);
	free(str);
}

int check_lent(char **map)
{
    int i = -1;
    int lent = ft_strlen(map[i + 1]);
    
    while(map[++i])
    {
        if(map[i + 1] == NULL)
            lent--;
        if(ft_strlen(map[i]) != lent)
            return -1;
    }
    return (lent - 1);
}

int check_map_1(char *s, int lent)
{
	int j = 0;
	while(lent-- > 0)
    {
        if(s[lent] != '1')
            return 1;
        
    }
	return 0;
}

void	check_byte(t_solong *attribut, char *line, int i, int lent)
{
	int j;

	j = -1;
	while(++j < lent)
	{
		if((j == 0 || j == lent) && line[j] != '1')
		{
			attribut->error = 1;
			return ;
		}
		else if(line[j] == 'C')
			attribut->count_coin++;
		else if(line[j] == 'E')
			attribut->exit = 1;
		else if(line[j] == 'P' && attribut->p_x == -1)
		{
			attribut->p_y = j;
			attribut->p_x = i;
		}
		else if (line[j] == '1' || line[j] == '0')
			continue ;
		else
		{
			attribut->error = 1;
			return ;
		}
	}
}
void	parse_map(t_solong *attribut)
{
	int i;
	int j;
	int lent;
	
	i = 0;
	j = 0;
	lent = check_lent(attribut->map);
	if (lent == -1)
		attribut->error = 1;
	while(attribut->map[i])
	{
		if((!i || !attribut->map[i + 1]) && check_map_1(attribut->map[i], lent))
			attribut->error = 1;
		check_byte(attribut, attribut->map[i], i, lent);
		i++;
	}
	if(attribut->exit < 1 || attribut->error == 1)
	{
		frealltab(attribut->map);
		free(attribut->map);
		exit(1);
	}
	i = -1;
	//while(attribut->map[++i])
	//	printf("%s", attribut->map[i]);
	//printf("%s", attribut->map[i]);
	//printf("%p", attribut->map);
	frealltab(attribut->map);
	free(attribut->map);
	printf("%p\n", attribut->map);
	system("leaks a.out");
	exit(6);
}
int main(int argc, char **argv)
{
	t_solong attribut;
	int i;
	char *s;

	i = 0;
	attribut.map = NULL;
	attribut.p_x = -1;
	check_ext_map(argc, argv, &attribut);
	attribut.fd = open (argv[1], O_RDWR);
	while ((s = get_next_line(attribut.fd)) != 0)
	{
		i++;
		free(s);
	}
	close(attribut.fd);
	attribut.map = malloc((i + 1) * sizeof(char *));
	attribut.fd = open (argv[1], O_RDWR);
	i = 0;
	while ((attribut.map[i++] = get_next_line(attribut.fd)) != 0);
	attribut.map[i] = NULL;
	close(attribut.fd);
	parse_map(&attribut);
	int j;
	i = -1;
	//printf("dddd");
	frealltab(attribut.map);
	free(attribut.map);
	system("leaks a.out");
	//while(1);
}