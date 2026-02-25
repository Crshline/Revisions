#include <stdlib.h>
#include <stdio.h>

void	find_subsets(int target, int *set, int set_len, int *subset, int subset_len, int index)
{
	if(target == 0)
	{
		for(int i = 0; i < subset_len; i++)
		{
			printf("%d", subset[i]);
			if(i < subset_len - 1)
				printf(" ");
		}
		printf("\n");
	}
	if(index >= set_len)
		return;
	for(int i = index; i < set_len; i++)
	{
		subset[subset_len] = set[i];
		find_subsets(target - set[i], set, set_len, subset, subset_len + 1, i + 1);
	}
}

int main(int ac, char **av)
{
	if(ac < 2)
		return(1);
	int size = ac - 2;
	int *set = NULL;
	int *subset = NULL;
	if(size > 0)
	{
		set = malloc(sizeof(int) * size);
		subset = malloc(sizeof(int) * size);

		if(!set || !subset)
		{
			free(set);
			free(subset);
			return(1);
		}
		for(int i = 0; i < size; i++)
			set[i] = atoi(av[i + 2]);
	}
	find_subsets(atoi(av[1]), set, size, subset, 0, 0);
	free(set);
	free(subset);
	return(0);
}