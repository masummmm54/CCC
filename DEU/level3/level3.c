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

char **dup_map(char **map, int h, int w)
{

	char **dup_map = malloc(sizeof(char *) * h + 1);
	int i = 0;
	int j = 0;
	while(i < h)
	{
		j = 0;
		dup_map[i] = malloc(w + 1);
		while (j < w)
		{
			if (map[i][j] == 'X')
				dup_map[i][j] = '1';
			dup_map[i][j] = '0';
			j++;
		}
		i++;
	}


	return (dup_map);
}

// ASSDWDSDWWDSS x = 1 y = 0
int	move_pos(char **map, char *moves, int x, int y, int h, int w)
{
	for (int i = 0; moves[i + 1]; i++)
	{
		map[y][x] = '1';
		if (moves[i] == 'S')
		{
			y -= 1;
		}
		else if (moves[i] == 'W')
		{
			y += 1;
		}
		else if (moves[i] == 'D')
		{
			x += 1;
		}
		else if (moves[i] == 'A')
		{
			x -= 1;
		}
		if (x >= w || y >= h || x < 0 || y < 0)
			return (0);
		if (map[y][x] == '1')
		{
			return (0);
		}
	}
	return (1);
}

int is_valid(char **map, char *moves, int w, int h, int x, int y)
{
	//printf("x = %d\n", x);
	//printf("y = %d\n", y);
	//printf("w = %d\n", w);
	//printf("h = %d\n", h);
	//if (x >= w || y >= h || x < 0 || y < 0)
	//	return (0);
	//is_valid(map, moves, w, h, x + 1, y);
	//is_valid(map, moves, w, h, x, y + 1);

	for(int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			map = dup_map(map, h, w);
			if (move_pos(map, moves, j, i, h, w))
				return (1);
		}
	}

	return (0);
}


void level2(char *s, int w, int h, FILE *file)
{
	size_t bufsize = 1;
	size_t lineline;
	char **map = malloc(sizeof(char *) * h);
	int x = 0;
	char *line;
	line = NULL;
	for (int i = 0; i < h; i++)
	{
		lineline = getline(&line, &bufsize, file);
		map[i] = strdup(line);
	}

	
	getline(&line, &bufsize, file);
	char *inputs = strdup(line);
	char **valid_map = dup_map(map, h, w);

	if (is_valid(valid_map, inputs, w, h, 0, 0))
		printf("VALID\n");
	else
		printf("INVALID\n");
	//if (move_pos(map, inputs, 1, 2, h, w))
	//	printf("VALID\n");
	//else
	//	printf("INVALID\n");

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
	FILE *file = fopen("result", "r");
	char *line;
	size_t bufsize = 1;
	size_t lineline;

	lineline = getline(&line, &bufsize, file);
	int n = atoi(line);
	int i = 2;
	while (i < n + 2)
	{
		lineline = getline(&line, &bufsize, file);
		int w = atoi(line);
		int	h = atoi(line + is_space(line));
		level2(line, w , h, file);
		i++;
	}



	return (0);
}
