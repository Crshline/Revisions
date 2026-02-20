#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int i = 0;
	int len = 0;
	int *tab;

	if(start >= end)
		len = start - end + 1;
	else
		len = end - start + 1;

	tab = malloc(sizeof(int) * len);
	if(!tab)
		return(NULL);

	while(i <= len)
	{
		tab[i] = end;
		if(start >= end)
			end++;
		else	
			end--;
		i++;
	}
	return(tab);
}

int main()
{
	int *tab = ft_rrange(1, 9);
	int i = 0;

	while(i <= 8)
	{
		printf("%d", tab[i]);
		i++;
	}
	free(tab);
}