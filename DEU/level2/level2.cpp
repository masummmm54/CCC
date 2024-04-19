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

void height(char *s)
{
	int y = 0;
	int maxwitth = 0;
	int minwith = 0;
	for (int i = 0; s[i] ; i++)
	{
		if (maxwitth < y)
			maxwitth = y;
		if (minwith > y)
			minwith = y;
		if (s[i] == 'W')
			y++;
		else if (s[i] == 'S')
			y--;
	}

	printf("%d\n", maxwitth - minwith + 1);
}

void width(char *s)
{
	int y = 0;
	int maxwitth = 0;
	int minwith = 0;
	for (int i = 0; s[i] ; i++)
	{
		if (maxwitth < y)
			maxwitth = y;
		if (minwith > y)
			minwith = y;
		if (s[i] == 'D')
			y++;
		else if (s[i] == 'A')
			y--;
	}

	printf("%d ", maxwitth - minwith + 1);
}


void level2(char *s)
{
	width(s);
	height(s);

}


int is_space(char *s)
{
	int i = 0;
	while (s[i] && s[i] != ' ')
	{
		i++;
	}
	return (i);
}


int main ()
{
	FILE *file = fopen("level2_5.in", "r");
	char *line;
	size_t bufsize = 1;
	size_t lineline;

	lineline = getline(&line, &bufsize, file);
	int n = atoi(line);
	int i = 2;
	while (i < n + 2)
	{
		lineline = getline(&line, &bufsize, file);
		
		level2(line);
		i++;
	}



	return (0);
}
