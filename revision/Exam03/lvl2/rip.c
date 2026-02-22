#include <stdio.h>

int balanced(char *str)
{
	int balance = 0;
	for(int i = 0; str[i]; i++)
	{
		if(str[i] == '(')
			balance++;
		else if(str[i] == ')')
			balance--;
		if(balance < 0)
			return(0);
	}
	return(balance == 0);
}

void	find_solutions(char *str, int index, int removed, int)
{
	if(str[index] == '\0')
	{
		if(balanced(str))
			puts(str);
		return;
	}
	find_solutions(str, index + 1);
	if(str[index] == '(' || str[index] == ')')
	{
		char temp = str[index];
		str[index] = ' ';
		find_solutions(str, index + 1);
		str[index] = temp;
	}
}

int main(int ac, char **av)
{
	if(ac != 2)
		return(1);
	find_solutions(av[1], 0);
	return(0);
}
