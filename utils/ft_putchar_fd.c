/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:01:22 by akhouya           #+#    #+#             */
/*   Updated: 2022/04/25 02:25:45 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}
