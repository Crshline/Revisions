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
		return;
	}
	if(target < 0 || index >= set_len)
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
	int set[size];
	int subset[size];

	for(int i = 0; i < size; i++)
		set[i] = atoi(av[i + 2]);
	find_subsets(atoi(av[1]), set, size, subset, 0, 0);
	return(0);
}