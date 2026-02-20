#include <unistd.h>

void	caplast(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			if(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
				str[i] -= 32;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			if(str[i] > 0 && str[i + 1] != ' ' && str[i + 1] != '\t')
				str[i] += 32;
		}
		write(1, &str[i++], 1);
	}
}


int main(int ac, char **av)
{
	int i;
	if(ac < 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	i = 1;
	while(i < ac)
	{
		caplast(av[i]);
		write(1, "\n", 1);
		i++;
	}
}