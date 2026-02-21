#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	if(ac != 2 || !av[1])
		return(1);
	int len = strlen(av[1]);
	static char buf[999999];
	int i = 0;
	int j;
	int k;
	while((j = read(0, buf + i, 1024)) > 0)
		i += j;
	if(j < 0)
		return(write(2, "Error: \n", 1024), 1);
	for(k = 0; k < i; k++)
	{
		if(k + len <= i && !memcmp(av[1], buf + k, len))
		{
			for(int l = 0; l < len; l++)
				write(1, "*", 1);
			k += len - 1;
		}
		else	
			write(1, buf + k, 1);
	}
	return(0);
}