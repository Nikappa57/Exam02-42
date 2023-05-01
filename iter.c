#include "unistd.h"

int	check_char(char *str, int len, char c)
{
	int	i;

	i = 0;
	while (str[i] && ((i < len) || (len == -1)))
		if (str[i++] == c)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!check_char(argv[1], i, argv[1][i])
				&& check_char(argv[2], -1, argv[1][i]))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
