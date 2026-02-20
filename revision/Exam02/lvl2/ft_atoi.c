#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int i = 0;
	int result = 0;
	int signe = 1;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			signe = -signe;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return(result * signe);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		printf("%d", ft_atoi(av[1]));
	}
}