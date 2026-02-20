#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int j;
	int temp;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if(tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}