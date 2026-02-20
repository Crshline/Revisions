#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if(n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

int	ft_atoi(char *str)
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

int main(int ac, char **av)
{
	int i = 1;
	int nb = ft_atoi(av[1]);

	if(ac != 2)
	{
		write(1, "\n", 1);
		return(0);
	}

	while(i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		ft_putnbr(i * nb);
		write(1, "\n", 1);
		i++;
	}

}