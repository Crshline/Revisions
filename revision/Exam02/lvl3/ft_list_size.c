#include "ft_list.h"
#include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	while(begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return(i);
}

int main()
{
	t_list a, b, c;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("%d", ft_list_size(&a));
}