#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int n;
	int a;
	int b;

	if(ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);

		if(a > b)
			n = a;
		else
			n = b;

		while(n > 0)
		{
			if(a % n == 0 && b % n == 0)
			{
				printf("%d", n);
				break;
			}
			n--;
		}
	}
	printf("\n");
}