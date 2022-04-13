#ifndef SOLONG_H
# define SOLONG_H
# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>

typedef struct s_lent
{
    int x;
    int y;
} t_lent;
typedef struct s_mlx
{
    void *mlx;
    void *imgWall;
    void *imgNori;
    void *win;
    //int j;
    int img_w;
    int img_h;
} t_mlx;
typedef struct s_solong
{
    int count_coin;
    int p_x;
    int p_y;
    int exit;
    void *imgPlayer;
    t_lent lent;
    char **map;
    int fd;
    int error;
    t_mlx tmlx;

} t_solong;
//gcc solong.c utils/*.c -lmlx -framework OpenGL -framework Appkit

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	frealltab(char **str);
char	*ft_strdup(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

# endif