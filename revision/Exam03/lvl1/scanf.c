#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

int	match_space(FILE *f)
{
	int	c;

	while ((c = fgetc(f)) != EOF && isspace(c))
		;
	if (c == EOF)
		return (-1);
	ungetc(c, f);
	return (0);
}

int	match_char(FILE *f, char c)
{
	int	read = fgetc(f);
	if (read == EOF)
		return (-1);
	if (read == c)
		return (1);
	ungetc(read, f);
	return (0);
}

int	scan_char(FILE *f, va_list ap)
{
	int	c = fgetc(f);
	if (c == EOF)
		return (-1);
	char *ptr = va_arg(ap, char *);
	*ptr = (char)c;
	return (1);
}

int	scan_int(FILE *f, va_list ap)
{
	int		c = fgetc(f);
	long	res = 0;
	int		signe = 1;
	int		digits = 0;
	
	if (c == '-' || c == '+')
	{
		if (c == '-')
			signe = -signe;
		c = fgetc(f);
	}
	while (isdigit(c))
	{
		digits = 1;
		res = res * 10 + (c - 48);
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (!digits)
		return (-1);
	int *ptr = va_arg(ap, int *);
	*ptr = (int)(res * signe);
	return (1);
}

int	scan_string(FILE *f, va_list ap)
{
	char	*str = va_arg(ap, char*);
	int		i = 0;
	int		c;

	while ((c = fgetc(f)) != EOF && !isspace(c))
		str[i++] = (char)c;
	if (c != EOF)
		ungetc(c, f);
	if (i == 0)
		return (-1);
	str[i] = '\0';
	return (1);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
	case 'c':
		return (scan_char(f, ap));
	case 'd':
		match_space(f);
		return (scan_int(f, ap));
	case 's':
		match_space(f);
		return (scan_string(f, ap));
	case EOF:
		return (-1);
	default:
		return (-1);
	}
}

int	ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int	nconv;
	int	c;

	nconv = 0;
	c = fgetc(f);
	if (c == EOF)
		return (EOF);
	ungetc(c, f);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break ;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break ;
		}
		else if (match_char(f, *format) != 1)
			break ;
		format++;
	}
	if (ferror(f))
		return (EOF);
	return (nconv);
}

int	ft_scanf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return (ret);
}

int	main(void)
{
	int n;

	printf("Tape un nombre: ");
	ft_scanf("%d", &n);
	printf("Tu as tapé: %d\n", n);

	return (0);
}