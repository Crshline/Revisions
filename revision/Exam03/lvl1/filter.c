#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

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
	if(ac != 2 || !av[1][0])
		return(1);
	int len = ft_strlen(av[1]);
	int cap = 1024;
	char *buf = malloc(cap);
	if(!buf)
		return(perror("Error"), 1);
	int i = 0;
	int j;
	int k;
	while((j = read(0, buf + i, 1024)) > 0)
	{
		i += j;
		if(i + 1024 > cap)
		{
			cap *= 2;
			char *tmp = realloc(buf, cap);
			if(!tmp)
			{
				free(buf);
				return(perror("Error"), 1);
			}
			buf = tmp;
		}
	}
	if(j < 0)
	{
		free(buf);
		return(perror("Error"), 1);
	}
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
	free(buf);
	return(0);
}