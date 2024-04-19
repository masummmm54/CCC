
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char *manupulate(char *line, int m, int R, int P, int S);
int is_space(char *s, char sep);


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




void	tournemant(char *s, int m)
{
	int	R = atoi(s);
	int	P = atoi(s + is_space(s, 'R') + 1);
	int	S = atoi(s + is_space(s, 'P') + 1);
	s = manupulate(s, m, R, P, S);
	char *result = malloc( m / 2  + 1);
	char *result1 = malloc( m / 4  + 1);
	for (int i = 0; i < m; i += 2)
	{
		result[i / 2] = fight(s[i], s[i + 1]);
	}
	printf("%s\n", s);
	//printf("%s  ", result);
	for (int i = 0; i < m / 2; i += 2)
		result1[i / 2] = fight(result[i], result[i + 1]);
	result1[m / 4] = '\0';
	//printf("%s\n", result1);
}

int is_space(char *s, char sep)
{
	int i = 0;
	while (s[i] && s[i] != sep)
	{
		i++;
	}
	return (i);
}

char *manupulate(char *line, int m, int R, int P, int S)
{

	char *newline = malloc (m + 1);
	int i = 0;
	while (R > 0)
	{
		if (R != 0 && P != 0)
		{
			newline[i] = 'P';
			newline[i + 1] = 'R';
			P--;
			R--;
			if (R > P && R >= 2)
			{
				i += 2;
				newline[i] = 'R';
				newline[i + 1] = 'R';
				R--;
				R--;
			}
		}
		else if (R != 0 && P == 0 && R != 1)
		{
			newline[i] = 'R';
			newline[i + 1] = 'R';
			R--;
			R--;
		}
		else if (R == 1)
		{
			newline[i] = 'R';
			newline[i + 1] = 'S';
			R--;
			S--;
		}
		i += 2;
	}

	while (P > 0)
	{
		if (P != 1)
		{
			newline[i] = 'P';
			newline[i + 1] = 'P';
			P--;
			P--;
		}
		else if (P == 1)
		{
			newline[i] = 'P';
			newline[i + 1] = 'S';
			P--;
			S--;
		}
		i += 2;
	}

	while (S > 0)
	{
		newline[i] = 'S';
		newline[i + 1] = 'S';
		S--;
		S--;
		i += 2;
	}

	newline[m] = '\0';
	return (newline);
}



int main ()
{
	FILE *file = fopen("level4_1.in", "r");
	char *line = NULL;
	size_t bufsize = 0;
	size_t lineline;

	lineline = getline(&line, &bufsize, file);
	int n = atoi(line);
	int	m = atoi(line + is_space(line, ' '));
	int i = 2;
	while (i < n + 2)
	{
		lineline = getline(&line, &bufsize, file);
		tournemant(line, m);
		i++;
	}

	free(line);
	fclose(file);
	return (0);
}

