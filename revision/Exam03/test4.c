#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	permutation(char *str, int start, int len)
{
	char c;
	if(start == len - 1)
	{
		write(1, str, len);
		write(1, "\n", 1);
		return;
	}
	for(int i = start; i < len; i++)
	{
		c = str[start];
		str[start] = str[i];
		str[i] = c;
		permutation(str, start + 1, len);
		c = str[start];
		str[start] = str[i];
		str[i] = c;
	}
}

int main(int ac, char **av)
{
	if(ac != 2)
		return(1);
	permutation(av[1], 0, strlen(av[1]));
	return(0);
}