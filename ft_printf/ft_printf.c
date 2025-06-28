/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:17:47 by root              #+#    #+#             */
/*   Updated: 2025/06/28 12:17:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(unsigned int num, int base)
{
	int		i = num % base;
	char 	*base_set = "0123456789abcdef";
	int		count = 0;

	if (num / base > 0)
		count += ft_putnbr(num / base, base);
	count += ft_putchar(base_set[i]);
	return (count);
}

int	ft_print_d(int nb)
{
	int		count = 0;

	if (nb < 0)
	{
		count += ft_putchar('-');
		if (nb == - 2147483648)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		nb = -nb;
	}
	count += ft_putnbr((unsigned int)nb, 10);
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int count = 0;
	int i = 0;

	va_start(ap, str);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd')
				count += ft_print_d(va_arg(ar, int));
			else if (str[i + 1] == 'x')
				count += ft_putnbr(va_arg(ap, unsigned int), 16);
			else if (str[i + 1] == 's')
				count += ft_putstr(va_arg(arg, char *));
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
