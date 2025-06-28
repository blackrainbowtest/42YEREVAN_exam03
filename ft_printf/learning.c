#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_putchar(char ch)
{
	return (write(1, &ch, 1));
}

int ft_putstr(char *str)
{
	int count = 0;
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int ft_putnbr(unsigned int nb, int base)
{
	int count = 0;
	char *base_set = "0123456789abcdef";
	int i = nb % base;

	if (nb / base > 0)
		count += ft_putnbr(nb / base, base);
	count += ft_putchar(base_set[i]);

	return (count);
}

int ft_print_d(int nb)
{
	int count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		if (nb == -2147483648)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		else
			nb = -nb;
	}
	count += ft_putnbr((unsigned int)nb, 10);
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list ap;
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
				count += ft_print_d(va_arg(ap, int));
			else if (str[i + 1] == 's')
				count += ft_putstr(va_arg(ap, char *));
			else if (str[i + 1] == 'x')
				count += ft_putnbr(va_arg(ap, unsigned int), 16);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	ft_printf("%s_%d_%x\n", "test", 125, 125);
	printf("%s_%d_%x\n", "test", 125, 125);
	return (0);
}
