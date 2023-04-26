#include <unistd.h>

int	check_char(char *str, int len, char c)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
		if (str[i++] == c)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!check_char(argv[1], i, argv[1][i]))
			write(1, &argv[1][i], 1);
		i++;
	}
	j = 0;
	while (argv[2][j])
	{
		if (!check_char(argv[1], i, argv[2][j])
                        && !check_char(argv[2], j, argv[2][j]))
                        write(1, &argv[2][j], 1);
		j++;
	}
	write(1, "\n", 1);
	
}
