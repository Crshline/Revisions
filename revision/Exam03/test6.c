#include <unistd.h>

int balanced(char *str)
{
	int balance = 0;
	for(int i = 0;str[i]; i++)
	{
		if(str[i] = '(')
			balance++;
		else if(str[i] = ')')
			balance--;
		if(balance < 0)
			return(0);
	}
	return(balance == 0);
}