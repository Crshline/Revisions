#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ft_strlen(char *str)
{
	int i =0;
	while(str[i])
		i++;
	return(i);
}

void	sort_str(char *str)
{
	for(int i = 0; str[i]; i++)
		for(int j = i + 1; str[j]; j++)
			if(str[i] > str[j])
			{
				char tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}

}

void	permutation(char *str, int start, int len)
{
	char c;
	if(start == len - 1)
	{
		write(1, str, len);
		write(1, "\n", 1);
		return;
	}
	for(int i = start; i < len; i++)
	{
		c = str[i];
		for(int j = i; j > start; j--)
			str[j] = str[j - 1];
		str[start] = c;
		permutation(str, start + 1, len);
		c = str[start];
		for(int j = start; j < i; j++)
			str[j] = str[j + 1];
		str[i] = c;
	}
}

int main(int ac, char **av)
{
	if(ac != 2)
		return(1);
	sort_str(av[1]);
	permutation(av[1], 0, ft_strlen(av[1]));
	return(0);
}