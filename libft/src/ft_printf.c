/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:15 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/17 15:41:20 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispach(va_list args, char c, int count)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int), count));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), count));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), count));
	else if (c == '%')
		return (ft_putchar('%', count));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, int), count));
	else if (c == 'x')
		return (ft_hexa(va_arg(args, int), count, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_hexa(va_arg(args, int), count, "0123456789ABCDEF"));
	else if (c == 'p')
	{
		count += 2;
		write(1, "0x", 2);
		return (ft_pointer(va_arg(args, long long), count, "0123456789abcdef"));
	}
	else if (c != '\0')
		return (ft_putchar(c, count));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = ft_dispach(args, str[i + 1], count);
			i++;
		}
		else
		{
			write(1, str + i, 1);
			count++;
		}
		i++;
	}
	return (count);
}
/* 
int main(void)
{
	int i;
	int n;
	
	n = -864515;

	i = ft_printf("salut ca%f va", (void *)-14523);
	printf("%d\n", i);
	i = printf("%p", (void *)-14523);
	printf("%d\n", i);
	i = ft_printf("salut %X\n", 16);
	printf("%d\n", i);
	i = printf("salut %X\n", 16);
	printf("%d\n", i);
	return (0);
} 
 */