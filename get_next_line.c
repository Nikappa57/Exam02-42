#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 999999

char *get_next_line(int fd)
{
	int	i;
	char	c;
	int	bytes;
	char	*buffer;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	i = 0;
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	while ((bytes = read(fd, &c, 1)) > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
	}
	if (bytes <= 0 && i == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

/*
# include <strings.h>
# include <fcntl.h>
# include <stdio.h>
int main(int ac, char **av)
{
	int		fd;
	char	*line;
	(void)ac;

	fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)) != 0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	system("leaks a.out");
	return (0);
} */
