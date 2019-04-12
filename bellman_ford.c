#include <stdio.h>
const int INF = 1<<10;
const int null = -1;

struct edge {
	int u, v, w;
}E[6];

int d[4];
int p[4];

void init_graph(int v, int s) {
	int i, j;
	for(i = 0; i < v; ++i) {
		d[i] = INF;
		p[i] = null;
	}
	d[s] = 0;
}

void relax(int u, int v, int w_uv) {
	if(d[v] > d[u] + w_uv) {
		d[v] = d[u] + w_uv;
		p[v] = u;
	}
}

int bellman_ford() {
	int i, j, k, l;
	int v = 4;
	int s = 0;
	printf("x? - x? <= ?\n");
	scanf("%d %d %d", &i, &j, &k);
	E[0].u = j;
	E[0].v = i;
	E[0].w = k;
	printf("x? - x? <= ?\n");
	scanf("%d %d %d", &i, &j, &k);
	E[1].u = j;
	E[1].v = i;
	E[1].w = k;
	printf("x? - x? <= ?\n");
	scanf("%d %d %d", &i, &j, &k);
	E[2].u = j;
	E[2].v = i;
	E[2].w = k;
	E[3].u = 0;
	E[3].v = 1;
	E[3].w = 0;
	E[4].u = 0;
	E[4].v = 2;
	E[4].w = 0;
	E[5].u = 0;
	E[5].v = 3;
	E[5].w = 0;
	init_graph(v, s);
	for(l = 0; l < 4; l++) {
		for(i = 0; i < 6; ++i) {
			relax(E[i].u, E[i].v, E[i].w);
		}
	}
}

int main() {
	bellman_ford();
	printf("x1 = %d, x2 = %d, x3 = %d, is the minimum solution\n", d[1], d[2], d[3]);
	return 0;
}
