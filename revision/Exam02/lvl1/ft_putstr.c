#include <unistd.h>

void	ft_putstr(char *str)
{
	size_t i = 0;
	while(str && str[i])
		write(1, &str[i++], 1);
}

int main(int ac, char **av)
{
	if(ac == 2)
		ft_putstr(av[1]);
	return(0);
}