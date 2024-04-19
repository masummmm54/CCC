
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>



char	fight(char s1, char s2)
{

	if (s1 == s2)
		return (s1);
	else if ((s1 == 'P' && s2 == 'R') || (s2 == 'P' && s1 == 'R'))
		return ('P');
	else if ((s1 == 'S' && s2 == 'R') || (s2 == 'S' && s1 == 'R'))
		return ('R');
	else if ((s1 == 'P' && s2 == 'S') || (s2 == 'P' && s1 == 'S'))
		return ('S');
	return (0);
}


void	tournemant(char *s, int m)
{
	char result[m / 2];
	char result1[m / 4];

	for (int i = 0; i < m; i += 2)
		result[i / 2] = fight(s[i], s[i + 1]);
	for (int i = 0; i < m; i += 2)
		result1[i / 2] = fight(result[i], result[i + 1]);
	result1[m / 4] = '\0';
	printf("%s\n", result1);
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
	int	m = atoi(line + is_space(line));
	int i = 2;

	while (i < n + 2)
	{
		lineline = getline(&line, &bufsize, file);
		tournemant(line, m);
		i++;
	}


	return (0);
}
