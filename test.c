#include <stdio.h>
#include <stdlib.h>

int	count_path(char *path[])
{
	int i = 0;

	while(path[i])
	{
		i++;
		printf("%i\n", i);
	}
	return (i);
}

int main (void)
{
	char	*path;

	path = (char *)malloc(100);
	free(path);
	return (0);
}
