#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	calcul(int *tab, int col, int n)
{
	if(col == n)
	{
		for(int i = 0; i < n; i++)
		{
			fprintf(stdout, "%d", tab[i]);
			if(i < n - 1)
				fprintf(stdout, " ");
			else
				fprintf(stdout, "\n");
		}
		return;
	}
	for(int row = 0; row < n; row++)
	{
		int safe = 1;
		for(int i = 0; i < col; i++)
		{
			if(tab[i] == row || tab[i] - row == col - i || row - tab[i] == col - i)
			{
				safe = 0;
				break;
			}
		}
		if(safe)
		{
			tab[col] = row;
			calcul(tab, col + 1, n);
		}
	}
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int n = atoi(av[1]);
		if(n > 0)
		{
			int *tab = calloc(n, sizeof(int));
			if(tab)
			{
				calcul(tab, 0, n);
				free(tab);
			}
		}
	}
	return(0);
}