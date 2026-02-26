#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *gnl(int fd)
{
	static char buf[BUFFER_SIZE];
	static int i = 0;
	static int j = 0;

	int len = 0;
	int cap = BUFFER_SIZE;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	
	char *line = malloc(cap);
	if(!line)
		return(NULL);

	while(1)
	{
		if(i >= j)
		{
			i = 0;
			j = read(fd, buf, BUFFER_SIZE);
			if(j <= 0)
				break;
		}
		if(len == cap - 1)
		{
			cap *= 2;
			char *tmp = malloc(cap);
			if(!tmp)
				return(free(line), NULL);
			for(int k = 0; k < len; k++)
				tmp[k] = line[k];
			free(line);
			line = tmp;
		}
		line[len++] = buf[i++];
		if(line[len - 1] == '\n')
			break;
	}
	if(j < 0 || len == 0)
		return(free(line), NULL);
	line[len] = '\0';
	return(line);
}