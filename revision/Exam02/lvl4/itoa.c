#include <stdio.h>

char	*ft_itoa(int nbr)
{
	long nb = nbr;
	long temp = nb;
	char *str;
	int len = 0;

	len = (nb <= 0);
	while(temp != 0)
	{
		temp /= 10;
		len++;
	}
	
	str = malloc(sizeof(char) * len + 1);
	if(!str)
		return(NULL);
	
	str[0] = '\0';

	if(nb == 0)
		str[0] == '0';
	if(nb <= 0)
	{
		nb = -nb;
		str[0] = '-';
	}

	while(nb != 0)
	{
		str[--len] = nb % 10 + 48;
		nb /= 10;
	}
	return(str);
}