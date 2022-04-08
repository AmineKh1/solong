/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:22:52 by akhouya           #+#    #+#             */
/*   Updated: 2022/04/07 01:14:14 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include<string.h>

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
int check_map_carateres(char *s, int lent)
{
	int j = 0;
	while(lent-- > 0)
    {
        if(s[lent] != '1' && s[lent] != 'P' && s[lent] != 'C' 
        && s[lent] != 'E' && s[lent] != '0')
            return 1;
        
    }
	return 0;
}
int    check_map_(char **map, int nbr, int lent)
{
    int i = -1;
    int one = 0;
    int j = 0;
    while(map[++i] && one == 0)
    {
        if(i == 0 || i == nbr - 1)
            one = check_map_1(map[i], lent);
        if(map[i][0] != '1' || map[i][lent - 1] != '1')
            one = 1;
        one = check_map_carateres(map[i], lent);
    }
    return one;
}

int check_lent(char **map, int nbr)
{
    int i = -1;
    int lent = ft_strlen(map[i + 1]);
    
    while(map[++i])
    {
        if(i == nbr - 1)
            lent--;
        if(ft_strlen(map[i]) != lent)
            return -1;
    }
    return lent;
}

int check_map(char **map, int nbr)
{
    int e = 0;
    int c = 0;
    int p = 0;
    int i = -1;
    int one = 0;
    struct s_solong attribut;
    int lent;
    while(map[++i] != NULL)
    {
        if (strchr(map[i], 'E') != 0)
            e = 1;
        if (strchr(map[i], 'C') != 0)
            c = 1;
        if (strrchr(map[i], 'P') != 0)
            p++;
        if (strrchr(map[i], 'P') != strchr(map[i], 'P'))
            p++;
    }
    
    lent = check_lent(map, nbr);
    one = check_map_(map, nbr, lent);
    if(c == 0 || e == 0 || p != 1 || lent == -1 || one == 1)
        return 1;
    return 0;
}
int main(int argc, char **argv)
{
    int fd;
    char **map;
    char *s;
    int i = 0;
    int j = 0;
    int lent = 0;
    fd = open("map.ber", O_RDWR);
    while ((s = get_next_line(fd)) != 0)
        i++;
    close(fd);
    map = malloc((i + 1) * sizeof(char*));
    lent = i;
    fd = open("map.ber", O_RDWR);
    while ((s = get_next_line(fd)) != 0)
        map[j++] = s;
    map[j] = NULL;
    if(check_map(map, lent) != 0)
    {
        printf("error");
        return 1;
    }
    printf("nadi");
}