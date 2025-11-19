#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int **map, h, w, bx, by, bs;
	char e, o, f;
} t_data;

int min3(int a, int b, int c) {
	if (a <= b && a <= c)
		return a;
	else if (b <= c)
		return b;
	return c;
}

void free_map(int **m, int h) {
	if (!m) return;
	while (h--) free(m[h]);
	free(m);
}

int** alloc_map(int h, int w) {
	int **m = malloc(h * sizeof(int*));
	if (!m) return NULL;
	for (int i = 0; i < h; i++) {
		m[i] = calloc(w, sizeof(int));
		if (!m[i]) {
			free_map(m, i);
			return NULL;
		}
	}
	return m;
}

int read_map(FILE *f, t_data *d) {
	if (fscanf(f, "%d%c%c%c\n", &d->h, &d->e, &d->o, &d->f) != 4 ||
		d->h < 1 || d->e < 32 || d->e > 126 || d->o < 32 || d->o > 126 ||
		d->f < 32 || d->f > 126 || d->e == d->o || d->e == d->f || d->o == d->f)

		return 0;

	char *line = NULL;
	size_t len = 0;
	d->w = -1;
	d->bs = 0;

	for (int y = 0; y < d->h; y++) {
		if (getline(&line, &len, f) == -1)
			return free(line), free_map(d->map, d->h), 0;
		
		int x = 0;
		while (line[x] && line[x] != '\n')
			x++;
		
		// Première ligne : définir largeur et allouer
		if (d->w == -1) {
			if (x < 1)
				return free(line), 0;
			d->w = x;
			if (!(d->map = alloc_map(d->h, d->w)))
				return free(line), 0;
		}
		// Lignes suivantes : vérifier largeur
		else if (x != d->w)
			return free(line), free_map(d->map, d->h), 0;
		
		// Valider et remplir
		for (int i = 0; i < x; i++) {
			if (line[i] != d->e && line[i] != d->o)
				return free(line), free_map(d->map, d->h), 0;
			d->map[y][i] = (line[i] == d->o);
		}
	}
	
	free(line);
	return 1;
}


void find_bsq(t_data *d) {
	int *prev = calloc(d->w, sizeof(int));
	int *curr = calloc(d->w, sizeof(int));
	
	if (!prev || !curr) {
		free(prev);
		free(curr);
		return;
	}
	for (int y = 0; y < d->h; y++) {
		for (int x = 0; x < d->w; x++) {
			curr[x] = d->map[y][x] ? 0 : 
					 (!x || !y) ? 1 : 
					 1 + min3(prev[x], curr[x-1], prev[x-1]);
			
			if (curr[x] > d->bs) {
				d->bs = curr[x];
				d->by = y - curr[x] + 1;
				d->bx = x - curr[x] + 1;
			}
		}
		int *tmp = prev;
		prev = curr;
		curr = tmp;
	}
	
	// Marquer le carré
	for (int y = d->by; y < d->by + d->bs; y++)
		for (int x = d->bx; x < d->bx + d->bs; x++)
			d->map[y][x] = 2;
	
	free(prev);
	free(curr);
}

void print_map(t_data *d) {
    char chars[] = {d->e, d->o, d->f};
    
    char *line = malloc(d->w + 2);
    if (!line) {
        fputs("Error\n", stderr);
        return;
    }
    line[d->w] = '\n';
    line[d->w + 1] = '\0';
    for (int y = 0; y < d->h; y++) {
        for (int x = 0; x < d->w; x++)
            line[x] = chars[d->map[y][x]];
        fputs(line, stdout);
    }
    free(line);
}

void process(FILE *f) {
	t_data d = {0};
	if (!read_map(f, &d)) {
		fputs("map error\n", stderr);
		return;
	}
	find_bsq(&d);
	print_map(&d);
	free_map(d.map, d.h);
}

int main(int ac, char **av) {
    if (ac > 2) {
        fputs("map error\n", stderr);
        return 1;
    }
    if (ac == 1) {
        process(stdin);
    } else {
        FILE *f = fopen(av[1], "r");
        if (!f) {
            fputs("map error\n", stderr);
            return 1;
        }
        process(f);
        fclose(f);
    }
    return 0;
}
