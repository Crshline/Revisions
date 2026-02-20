#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int data;
	struct s_list *next;
} t_list;

/* ---------------------------------------- Test des structures auto-referentes ---------------------------------------- */

// int main(void)
// {
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;

// 	node1 = malloc(sizeof(t_list));
// 	if(!node1)
// 		return(1);
// 	node2 = malloc(sizeof(t_list));
// 	if(!node2)
// 		return(1);
// 	node3 = malloc(sizeof(t_list));
// 	if(!node3)
// 		return(1);

// 	node1->data = 42;
// 	node2->data = 52;
// 	node3->data = 62;

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;

// 	t_list *tmp = node1;
//     while (tmp != NULL)
//     {
//         printf("%d\n", tmp->data); 
//         tmp = tmp->next;
//     }

// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return(0);
// }


// typedef struct s_complex
// {
// 	//char name[50];
// 	int longueur;
// 	int largeur;
// } t_complex;

/* ---------------------------------------- Test des structures avec malloc ---------------------------------------- */

// t_complex *new_point(int longueur, int largeur)
// {
// 	t_complex *new;
// 	new = malloc(sizeof(t_complex));
// 	if(!new)
// 		return(NULL);
// 	new->longueur = longueur;
// 	new->largeur = largeur;
// 	return(new);
// }

// void	afficher_rectangle(t_complex *r)
// {
// 	printf("J'affiche mon rectangle : longueur : %d, largeur : %d\n", r->longueur, r->largeur);
// }

// int main()
// {
// 	t_complex *ptr1;
// 	t_complex *ptr2;

// 	ptr1 = new_point(10, 20);
// 	ptr2 = new_point(50, 60);

// 	afficher_rectangle(ptr1);
// 	afficher_rectangle(ptr2);

// 	free(ptr1);
// 	free(ptr2);
// }
/* ---------------------------------------- Test des tableaux de pointeurs ---------------------------------------- */

// char *strcpy(char *dest, const char *src)
// {
// 	int i = 0;
// 	while(src[i])
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return(dest);
// }
// void afficherrectangle(t_complex *rectangle)
// {
// 	printf("Afficher le nom de mon rectangle : %s aux mesures longueur : %d et largeur : %d\n", rectangle->name, rectangle->longueur, rectangle->largeur);
// }

// int main()
// {
// 	t_complex rec1;
// 	t_complex rec2;
// 	t_complex rec3;
// 	t_complex *rectangle[3];
// 	int i = 0;

// 	strcpy(rec1.name, "Rectangle 1");
// 	rec1.longueur = 10;
// 	rec1.largeur = 20;

// 	strcpy(rec2.name, "Rectangle 2");
// 	rec2.longueur = 30;
// 	rec2.largeur = 40;

// 	strcpy(rec3.name, "Rectangle 3");
// 	rec3.longueur = 2000;
// 	rec3.largeur = 1000;

// 	rectangle[0] = &rec1;
// 	rectangle[1] = &rec2;
// 	rectangle[2] = &rec3;

// 	while(i < 3)
// 	{
// 		afficherrectangle(rectangle[i]);
// 		i++;
// 	}
// }

/* ---------------------------------------- Test des pointeurs simples avec fonction annexe ---------------------------------------- */

// int	afficherxy(t_complex r)
// {
// 	int air = r.longueur * r.largeur;
// 	printf("J'affiche mon aire : %d\n", air);
// 	return(air);
// }

// int main(void)
// {
// 	t_complex r;
// 	t_complex *ptr;

// 	r.longueur = 5;
// 	r.largeur = 10;

// 	printf("J'affiche mes coordonees x : %d et y : %d\n", r.longueur, r.largeur);

// 	afficherxy(r);
// 	ptr = &r;

// 	printf("J'affiche mon adresse : %p\n", ptr);

// 	ptr->longueur = 100;
// 	ptr->largeur = 200;

// 	printf("J'affiche mes coordonees modifiees x : %d et y : %d\n", ptr->longueur, ptr->largeur);
// 	afficherxy(r);

/* ---------------------------------------- Test des pointeurs simples ---------------------------------------- */
// }

// int main(void)
// {
// 	t_complex p;
// 	t_complex *ptr;

// 	p.x = 10;
// 	p.y = 20;

// 	printf("Avant modification : x : %d, y : %d\n", p.x, p.y);

// 	ptr = &p;

// 	printf("Adresse de p : %p\n", ptr);

// 	ptr->x = 100;
// 	ptr->y = 200;

// 	printf("Apres modification : x : %d, y : %d\n", ptr->x, ptr->y);

// 	(*ptr).x = 300;
// 	(*ptr).y = 400;

// 	printf("Apres une nouvelle modification : x : %d, y : %d\n", (*ptr).x, (*ptr).y);
// }