#include <unistd.h>
#include <stdarg.h>

int	put_str(char *str)
{
	int	len;
	
	len = 0;
	while (str && str[len])
		len++;
	if (!str || (len == 0))
		return (write(1, "(null)", 6));
	return (write(1, str, len));
}

void	put_nbr(long number, int base_n, char *base, int *size)
{
	if (number >= base_n)
		put_nbr(number / base_n, base_n, base, size);
	*size += write(1, &base[number % base_n], 1);
}

void put_nbr_sign(long number, int base_n, char *base, int *size)
{
	if (number < 0)
	{	
		*size += write(1, "-", 1);
		number *= -1;
	}
	put_nbr(number, base_n, base, size);

}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	size;
	
	i = 0;
	size = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%' && str[i + 1] == 's' && (i += 2))
			size += put_str(va_arg(args, char *));
		else if (str[i] == '%' && str[i + 1] == 'd' && (i += 2))
			put_nbr_sign(va_arg(args, int), 10, "0123456789", &size);
		else if (str[i] == '%' && str[i + 1] == 'x' && (i += 2))
			put_nbr(va_arg(args, unsigned int), 16, "0123456789abcdef", &size);
		else
			size += write(1, &str[i++], 1);
	}
	va_end(args);
	return (size);
}

