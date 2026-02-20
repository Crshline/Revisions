#include <unistd.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list i = lst;
	t_list j;
	t_list temp;
	while(i)
	{
		j = i->next;
		while(j)
		{
			if(cmp(i->data, j->data) == 0)
			{
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
			j->next;
		}
		i->next;
	}
	return(lst);
}