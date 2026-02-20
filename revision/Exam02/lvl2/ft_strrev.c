#include <stdio.h>

char    *ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	int temp;

	while(str[i])
		i++;
	i--;
	while(i > j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return(str);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		ft_strrev(av[1]);
		printf("%s", av[1]);
	}
}