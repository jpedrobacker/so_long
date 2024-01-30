#include <stdio.h>

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
	char	*path[] = {"qoeioqwie", "238102938109", "aaaaaaaaaaaaaaaaaaaa",NULL};

	int i;
	i = count_path(path);
	printf("%i", i);
	return (0);
}
