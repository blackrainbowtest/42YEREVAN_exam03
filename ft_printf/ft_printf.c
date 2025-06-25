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