/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:20:55 by akhouya           #+#    #+#             */
/*   Updated: 2022/05/08 16:07:23 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
//# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "mlx.h"
# include <stdarg.h>

typedef struct s_lent
{
	int	x;
	int	y;
}	t_lent;

typedef struct s_solong
{
	void	*mlx;
	void	*imgwall;
	void	*imgnori;
	void	*imgplayer;
	void	*imgport;
	void	*win;
	int		img_w;
	int		img_h;
	char	**map;
	t_lent	lent;
	int		p_x;
	int		p_y;
	int		exit;
	int		count_coin;
	int		fd;
	int		error;
	int		movement;
}	t_solong;
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
int		mlx_move(int codekey, void *param);
void	parse_ma_drawing(t_solong *attribut);
int		close_dstroy(void *param);
void	parse_map(t_solong *attribut);
int		check_lent(char **map);
int		check_map_1(char *s, int lent);
void	check_byte(t_solong *attribut, char *line, int i, int lent);
void	check_ext_map(int argc, char **argv, t_solong *attribut);
void	check_byte_drawing(t_solong *attribut, char *line, int i, int lent);
void	parse_ma_drawingg(t_solong *attribut);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putnbr_base(unsigned long int nbr, char *base, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
int		ft_printf(const char *formatstring, ...);
void	condition_ext(t_solong *attribut, char **str);
#endif
