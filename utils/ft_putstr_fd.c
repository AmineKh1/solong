/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:00:57 by akhouya           #+#    #+#             */
/*   Updated: 2022/04/25 02:25:10 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1, count);
		return ;
	}	
	while (*s)
	{
		ft_putchar_fd(*s, fd, count);
		s++;
	}
}
