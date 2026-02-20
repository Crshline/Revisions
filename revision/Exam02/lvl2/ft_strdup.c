#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char *dest;
	int len = 0;
	int i = 0;
	if(src[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if(!dest)
		return(NULL);	
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}
int main(int ac, char **av)
{
	char *dest;
	if(ac == 2)
	{
		printf("%s\n", av[1]);
		dest = ft_strdup(av[1]);
		printf("%s\n", dest);
		free(dest);
	}
}