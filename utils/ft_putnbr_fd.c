/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:01:08 by akhouya           #+#    #+#             */
/*   Updated: 2022/04/25 02:25:37 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_putnbr_fd(int n, int fd, int *count)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		nbr = nbr * -1;
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd, count);
	else if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd, count);
		ft_putchar_fd(nbr % 10 + '0', fd, count);
	}
}
