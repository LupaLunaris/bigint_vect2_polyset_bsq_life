#include <stdlib.h>
#include <unistd.h>

int putchar(int c);

int main(int argc, char **argv)
{
	int w, h, iter, *board, *next, x, y, pen;
	char c;

	if (argc != 4 || !(w = atoi(argv[1])) || !(h = atoi(argv[2])))
		return 1;
	
	iter = atoi(argv[3]);
	
	if (!(board = calloc(w * h, sizeof(int))) || 
		!(next = calloc(w * h, sizeof(int))))
		return free(board), 1;

	x = y = pen = 0;

	/* Draw phase */
	while (read(0, &c, 1) == 1)
	{
		if (c == 'w' && y > 0) y--;
		else if (c == 's' && y < h - 1) y++;
		else if (c == 'a' && x > 0) x--;
		else if (c == 'd' && x < w - 1) x++;
		else if (c == 'x') pen = !pen;
		if (pen)
			board[y * w + x] = 1;
	}

	/* Game of Life simulation */
	for (int t = 0; t < iter; t++)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int n = 0; // nombre de voisins vivants
				for (int di = -1; di <= 1; di++)
					for (int dj = -1; dj <= 1; dj++)
						if ((di || dj) && i + di >= 0 && i + di < h && j + dj >= 0 && j + dj < w)
							n += board[(i + di) * w + (j + dj)];
				
				next[i * w + j] = (board[i * w + j] && (n == 2 || n == 3)) || (n == 3);
			}
		}
		
		/* Copy */
		for (int i = 0; i < h * w; i++)
			board[i] = next[i];
	}

	/* Print */
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			putchar(board[i * w + j] ? '0' : ' ');
		putchar('\n');
	}

	free(board);
	free(next);
	return 0;
}