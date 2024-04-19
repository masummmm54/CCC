#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int	count(char *s, char find)
{
	int count = 0;
	for (int i = 0; s[i] ; i++)
	{
		if (s[i] == find)
			count++;
	}
	return (count);
}


void level1(char *s)
{

	int counts[4];
	counts[0] = count(s, 'W');
	counts[1] = count(s, 'D');
	counts[2] = count(s, 'S');
	counts[3] = count(s, 'A');

	printf("%d %d %d %d\n", counts[0], counts[1], counts[2], counts[3]);

}


int main ()
{
	FILE *file = fopen("level1_5.in", "r");
	char *line;
	size_t bufsize = 1;
	size_t lineline;

	lineline = getline(&line, &bufsize, file);
	int n = atoi(line);
	int i = 2;
	while (i < n + 2)
	{
		lineline = getline(&line, &bufsize, file);
		level1(line);
		i++;
	}



	return (0);
}
