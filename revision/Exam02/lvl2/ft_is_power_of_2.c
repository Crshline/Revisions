#include <stdio.h>
#include <stdlib.h>

int	    is_power_of_2(unsigned int n)
{
	return(n > 0 && (n & (n - 1)) == 0);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		printf("%d", is_power_of_2(atoi(av[1])));
	}
}