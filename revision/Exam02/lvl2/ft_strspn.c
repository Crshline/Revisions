#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j;
	size_t count;

	while(s[i])
	{
		j = 0;
		count = 0;
		while(accept[j])
		{
			if(s[i] == accept[j])
				count = 1;
			j++;
		}
		if(count == 0)
			return(i);
		i++;
	}
	return(i);
}

int main(int ac, char **av)
{
	if(ac == 3)
		printf("%zu", ft_strspn(av[1], av[2]));
}