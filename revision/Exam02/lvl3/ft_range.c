#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int i = 0;
	int *tab;
	int len = 0;

	if(start >= end)
		len = start - end + 1;
	else 
		len = end - start + 1;

	tab = malloc(sizeof(int) * len);
	if(!tab)
		return(NULL);

	
	while(i < len)
	{
		tab[i] = start;
		if(start >= end)
			start--;
		else 
			start++;
		i++;
	}
	return(tab);
}

int main()
{
	int *tab = ft_range(1, 9);
	int i = 0;

	while(i < 8)
	{
		printf("%d", tab[i]);
		i++;
	}
	free(tab);
}