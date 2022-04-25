/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:24:59 by akhouya           #+#    #+#             */
/*   Updated: 2022/04/25 02:27:13 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	printf_help(va_list val, int *count, char formatstring)
{
	if (formatstring == 's')
		ft_putstr_fd(va_arg(val, char *), 1, count);
	else if (formatstring == 'i' || formatstring == 'd')
		ft_putnbr_fd(va_arg(val, int), 1, count);
	else if (formatstring == 'p')
	{
		ft_putstr_fd("0x", 1, count);
		ft_putnbr_base(va_arg(val, unsigned long), "0123456789abcdef", count);
	}
	else if (formatstring == '%')
		ft_putchar_fd(formatstring, 1, count);
	else if (formatstring == 'c')
		ft_putchar_fd(va_arg(val, int), 1, count);
	else if (formatstring == 'x')
		ft_putnbr_base(va_arg(val, unsigned int), "0123456789abcdef", count);
	else if (formatstring == 'X')
		ft_putnbr_base(va_arg(val, unsigned int), "0123456789ABCDEF", count);
	else if (formatstring == 'u')
		ft_putnbr_base(va_arg(val, unsigned int), "0123456789", count);
}

int	ft_printf(const char *formatstring, ...)
{
	int					*count;
	va_list				valist;
	int					i;

	va_start(valist, formatstring);
	count = malloc(sizeof(int));
	*count = 0;
	while (*formatstring)
	{
		if (*formatstring == '%')
		{
			formatstring++;
			printf_help(valist, count, *formatstring);
			if (*formatstring == '\0')
				break ;
		}
		else
			ft_putchar_fd(*formatstring, 1, count);
		formatstring++;
	}
	i = *count;
	free(count);
	return (i);
}
