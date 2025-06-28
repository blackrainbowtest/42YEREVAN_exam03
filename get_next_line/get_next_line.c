#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	char *result = malloc(99999);
	char tmp;
	int i = 0;
	int read_byte_count = 0;

	if (fd < 0)
		return (NULL);
	while ((read_byte_count = read(fd, &tmp, 1)) > 0)
	{
		result[i] = tmp;
		i++;
		if (tmp == '\n' || tmp == '\0')
			break ;
	}
	if (i == 0 || read_byte_count < 0)
	{
		free(result);
		return (NULL);
	}
	result[i] = '\0';
	printf("\033[0;31mDEBUG:\033[0;34m|%s\033[0m", result);
	return (result);
}

int main(int argc, char **argv)
{
	int fd = 0;
	char *line;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line  |%s", line);
		free(line);
		line = get_next_line(fd);
	}
	write(1, "\n", 1);
	return (0);
}