#include <stdio.h>
const int INF = 1<<10;
const int null = -1;

struct dist {
	int i, d;
}d[100];
int heap_size;
int G[100][100];
int p[100];
int VV;

void myswap (struct dist *u, struct dist *v) {
	int t = (*u).i;
	(*u).i = (*v).i;
	(*v).i = t;
	t = (*u).d;
	(*u).d = (*v).d;
	(*v).d = t;
}

int min(int a, int b) {
	if(a < b)
		return a;
	return b;
}

void init_graph(int v, int s) {
	int i, j;
	for(i = 1; i <= v; ++i) {
		for(j = 1; j <= v; ++j) {
			G[i][j] = INF;
			if(i == j)
				G[i][j] = 0;
		}
	}
	for(i = 1; i <= v; ++i) {
		d[i].d = INF;
		d[i].i = i;
		p[i] = null;
	}
	d[s].d = 0;
}

void minheapify(int i) {
	int l = 2*i;
	int r = 2*i + 1;
	int min = i;
	if(l <= heap_size && d[l].d < d[min].d) {
		min = l;
	}
	if(r <= heap_size && d[r].d < d[min].d) {
		min = r;
	}
	if(min != i) {
		myswap(&d[i], &d[min]);
		minheapify(min);
	}
}

void buildminheap() {
	int i;
	for(i = heap_size/2; i >= 1; --i) {
		minheapify(i);
	}
}

void decreasekey(int j, int key) {
	int k;
	if(d[j].d < key)
		return;
	d[j].d = key;
	while(j>1 && d[j].d < d[j/2].d) {
		myswap(&d[j], &d[j/2]);
		j /= 2;
	}
}

int extractmin() {
	int temp = d[1].i;
	myswap(&d[1], &d[heap_size]);
	heap_size--;
	minheapify(1);
	return temp;
}

void relax(int u, int v, int w_uv) {
	int ii, j, k;
	for(ii = 1; ii <= VV; ii++) {
		if(d[ii].i == u) {
			j = ii;
		}
		if(d[ii].i == v) {
			k = ii;
		}
	}
	if(d[k].d > d[j].d + w_uv) {
		decreasekey(k, d[j].d + w_uv);
		p[v] = u;
	}
}

int main() {
	int v, e, s, i, j, k, l;
	printf("Enter number of vertices, edges and starting vertex\n");
	scanf("%d", &v);
	scanf("%d", &e);
	scanf("%d", &s);
	init_graph(v, s);
	printf("Enter vertex u v w (u -> v : weight = w)\n");
	for(l = 1; l <= e; ++l) {
		scanf("%d %d %d", &i, &j, &k);
		G[i][j] = k;
	}
	heap_size = v;
	VV = v;
	buildminheap();
	while(heap_size >= 1) {
		int u = extractmin();
		for(j = 1; j <= v; ++j) {
			if(u == j)
				continue;
			if(G[u][j] != INF) {
				relax(u, j, G[u][j]);
			}
		}
	}
	
	printf("Distance from vertex = %d\n", s);
	for(i = 1; i <= v; ++i) {
		printf("Vertex = %d, shortest distance = %d\n", d[i].d, d[i].i);
	}
	return 0;
}

/*
Sample input : 
4 5 1
1 2 10
1 4 4
2 4 2
4 3 1
3 2 3
*/
