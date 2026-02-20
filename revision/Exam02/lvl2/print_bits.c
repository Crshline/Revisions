#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char bit;
	int i = 8;
	
	while(i--)
	{
		bit = ((octet >> i) & 1) + 48;
		write(1, &bit, 1);
	}
}

int main()
{
	unsigned char octet = 2;
	print_bits(octet);
}