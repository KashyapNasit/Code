#include <stdio.h>
const int INF = 1<<10;
const int null = -1;

int G[100][100];
int D[100][100];
int P[100][100];
int d[100][100][100];
int p[100][100][100];

int min(int a, int b) {
	if(a < b)
		return a;
	return b;
}

void init_graph(int v) {
	int i, j;
	for(i = 0; i < v; ++i) {
		for(j = 0; j < v; ++j) {
			G[i][j] = INF;
			D[i][j] = INF;
			P[i][j] = null;
			if(i == j)
				D[i][j] = 0;
		}
	}
}

int main() {
	int v, e, i, j, k, l;
	printf("Enter number of vertices: ");
	scanf("%d", &v);
	printf("Enter number of edges: ");
	scanf("%d", &e);
	init_graph(v);
	printf("Enter vertex u v w (u -> v : weight = w)\n");
	for(l = 0; l < e; ++l) {
		scanf("%d %d %d", &i, &j, &k);
		D[i-1][j-1] = G[i-1][j-1] = k;
		p[i-1][j-1][0] = i-1;
	}
	for(i = 0; i < v; ++i) {
		for(j = 0; j < v; ++j) {
			d[i][j][0] = D[i][j];
		}
	}
	for(k = 1; k < v; ++k) {
		for(i = 0; i < v; ++i) {
			for(j = 0; j < v; ++j) {
				if(i == j)
					continue;
				d[i][j][k] = min(d[i][j][k-1], d[i][k-1][k-1]+d[k-1][j][k-1]);
				if(d[i][j][k] == d[i][j][k-1]) {
					p[i][j][k] = p[i][j][k-1];
				} else {
					p[i][j][k] = p[k][j][k-1];
				}
			}
		}
	}
	printf("\nDistance\n");
	for(i = 0; i < v; ++i) {
		for(j = 0; j < v; ++j) {
			if(d[i][j][v-1] == null)
				printf("INF\t");
			else
				printf("%d\t", d[i][j][v-1]);
		}printf("\n");
	}
	printf("\nParent\n");
	for(i = 0; i < v; ++i) {
		for(j = 0; j < v; ++j) {
			if(i==j)
				printf("NULL\t");
			else
				printf("%d\t", p[i][j][v-1]+1);
		}printf("\n");
	}
	return 0;
}

/*
5
9
1 2 3
1 3 8
1 5 -4
2 5 7
2 4 1
3 2 4
4 3 -5
4 1 2
5 4 6
*/