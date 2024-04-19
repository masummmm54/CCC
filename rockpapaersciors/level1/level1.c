
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>



void	fight(char *s)
{

	if (s[0] == s[1])
		printf("%c\n",s[0]);
	else if ((s[0] == 'P' && s[1] == 'R') || (s[1] == 'P' && s[0] == 'R'))
		printf("P\n");
	else if ((s[0] == 'S' && s[1] == 'R') || (s[1] == 'S' && s[0] == 'R'))
		printf("R\n");
	else if ((s[0] == 'P' && s[1] == 'S') || (s[1] == 'P' && s[0] == 'S'))
		printf("S\n");
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
	//free(line);
	while (i < n + 2)
	{
		lineline = getline(&line, &bufsize, file);
		fight(line);
		i++;
		//free(line);
	}



	return (0);
}
