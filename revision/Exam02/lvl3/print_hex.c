#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int atoi(char *str)
{
	int i = 0;
	int result = 0;

	while(str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return(result);
}

void print_hex(int n)
{
	char *base = "0123456789abcdef";
	if(n >= 16)
		print_hex(n / 16);
	ft_putchar(base[n % 16]);
}

int main(int ac, char **av)
{
	if(ac == 2)
		print_hex(atoi(av[1]));
}