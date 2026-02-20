#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	unsigned int i = 0;
	int res;
	if(len == 0)
		return(0);

	res = tab[0];
	while(i < len)
	{
		if(tab[i] > res)
			res = tab[i];
		i++;
	}
	return(res);
}

int main()
{
	int tab[4] = {1, 6, 45, 15};
	printf("%d", max(tab, 4));

}