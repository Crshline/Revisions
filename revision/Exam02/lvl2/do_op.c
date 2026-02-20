#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int d1;
	int d2;
	int result = 0;
	if(ac == 4)
	{
		d1 = atoi(av[1]);
		d2 = atoi(av[2]);
		
		if(av[2][0] == '+')
			result = d1 + d2;
		else if(av[2][0] == '-')
			result = d1 - d2;
		else if(av[2][0] == '*')
			result = d1 * d2;
		else if(av[2][0] == '/')
			result = d1 / d2;
		else if(av[2][0] == '%')
			result = d1 % d2;
		printf("%d", result);
	}
	printf("\n");
}