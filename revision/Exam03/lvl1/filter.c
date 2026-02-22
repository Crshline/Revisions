#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t i = 0;
	while(i < len && ((const char *)s1)[i] == ((const char *)s2)[i])
		i++;
	if(i == len)
		return(0);
	return(((const char *)s1)[i] - ((const char *)s2)[i]);
}

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
		return(perror("Error"), 1);
	for(k = 0; k < i; k++)
	{
		if(k + len <= i && !ft_memcmp(buf + k, av[1], len))
		{
			for(int l = 0; l < len; l++)
				printf("*");
			k += len - 1;
		}
		else
			printf("%c", buf[k]);
	}
	return(0);
}