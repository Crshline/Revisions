#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);
}

int main(int ac, char **av)
{
	if(ac == 3)
	{
		printf("%s\n", av[1]);
		ft_strcpy(av[1], av[2]);
		printf("%s\n", av[1]);
	}
}