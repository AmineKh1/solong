#ifndef SOLONG_H
# define SOLONG_H
# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
typedef struct s_solong
{
    int count_coin;
    int p_x;
    int p_y;

};

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
# endif