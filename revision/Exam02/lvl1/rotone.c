#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	if(ac == 2)
	{
		while(av[1][i])
		{
			char c = av[1][i];
			if((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
				c += 1;
			else if(c == 'z' || c == 'Z')
				c -= 25;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}