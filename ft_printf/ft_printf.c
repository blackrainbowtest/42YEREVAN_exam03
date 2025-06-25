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