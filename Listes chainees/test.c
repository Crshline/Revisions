#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int ft_lstsize(t_list *lst)
{
	int i = 0;
	while(lst)
	{
		i++;
		lst = lst->next; 
	}
	return(i);
}

int main()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew(10);
	node2 = ft_lstnew(20);
	node3 = ft_lstnew(30);

	node1->next = node2;
	node2->next = node3;
	printf("Nombre de node : %d\n", ft_lstsize(node1));
	free(node1);
    free(node2);
    free(node3);
}
// t_list	*ft_lstnew(int content)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = *lst;
// 	*lst = new;
// }

// void	afficherhead(t_list *head)
// {
// 	t_list *actuel;

// 	actuel = head;
// 	while(actuel)
// 	{
// 		printf("Afficher le content : %d\n", actuel->content);
// 		actuel = actuel->next;
// 	}
// }
// int main(void)
// {
// 	t_list *head;

// 	head = NULL;

// 	ft_lstadd_front(&head, ft_lstnew(10));
// 	afficherhead(head);

// 	ft_lstadd_front(&head, ft_lstnew(52));
// 	afficherhead(head);

// 	free(head->next);
// 	free(head);
// }
// int	main(void)
// {
// 	t_list	*head;
// 	t_list *new;

// 	head = ft_lstnew(20);
// 	printf("Afficher le content : %d\n", head->content);
// 	printf("afficher son adresse : %p\n", head);
	
// 	new = ft_lstnew(10);
// 	printf("Afficher le content : %d\n", new->content);
// 	printf("afficher son adresse : %p\n", new);

// 	new->next = head;
// 	printf("new --> [%d] --> [%d] --> NULL\n", new->content, new->next->content);

// 	head = new;
// 	printf("Head --> [%d] --> [%d] --> NULL\n", head->content, head->next->content);

// 	free(head->next);
// 	free(head);
// }
