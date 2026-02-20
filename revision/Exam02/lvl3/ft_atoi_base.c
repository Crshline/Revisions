#include <stdio.h>

int get_digit(char c)
{
	if(c >= '0' && c <= '9')
		return(c - '0');
	else if(c >= 'a' && c <= 'f')
		return(c - 'a' + 10);
	else if(c >= 'A' && c <= 'F')
		return(c - 'A' + 10);
	return(-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int result = 0;
	int signe = 1;
	int digit;

	if(str[i] == '-')
	{
		signe = -signe;
		i++;
	}
	
	while(str[i])
	{
		digit = get_digit(str[i]);
		if(digit == -1 || digit >= str_base)
			break;
		result = result * str_base + digit;
		i++;
	}
	return(result * signe);
}
#include <stdlib.h>
int main(int ac, char **av)
{
	if(ac == 3)
	{
		printf("%d", ft_atoi_base(av[1], atoi(av[2])));
	}
}