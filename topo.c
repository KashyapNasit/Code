#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

struct node {
	int info;
	struct node *next;
};
typedef struct node NODE;

int i, j, k, l, m, e, v, timer = 0, k = 0;
NODE* adj[MAX];
int visited[MAX], topo[MAX];

NODE *newnode(int val){
	NODE *node = (NODE *) malloc(sizeof(NODE));
	node->info = val;
	node->next = NULL;
	return node;
}

void init(){
	for(i = 0; i <= v; i++){
		adj[i] = NULL;
		visited[i] = 0;
	}
}

NODE * push(int ind, int val){
    NODE* node = newnode(val);
    node->next = adj[ind];
    return node;
}

void dfs_visit(int v){
	int start, end;
	start = ++timer;
    visited[v] = 1;
    NODE * node = adj[v];
    while(node != NULL){
    	if(visited[node->info] == 0)
    		dfs_visit(node->info);
    	node = node->next;
    }
    end = ++timer;
    topo[k++] = v;
}

void dfs() {
	for(i = 1; i <= v; i++){
		if(visited[i]==0)
   		   	dfs_visit(i);
	}
}

void print_topo() {
	printf("Topological Sort : ");
	for(i = k - 1; i >= 0; --i){
		printf("%d ",topo[i]);
	}
	printf("\n");
}

void print_adjlist() {
	printf("Adj list\n");
	for(i = 1; i <= v; i++){
		NODE *node = adj[i];
		printf("%d : ", i);
		while(node != NULL){
			printf("%d ", node->info);
			node = node->next;
		}
		printf("\n");
	}
}

int main(){
	init();
	printf("Enter number of edges : ");
	scanf("%d", &e);
	printf("Enter number of vertices : ");
	scanf("%d", &v);
	printf("Enter %d edges (u v) such that edge is from 'u' to 'v'\n", e);
	for(i = 0; i < e; ++i){
	  int a, b;
	  scanf("%d %d",&a, &b);
	  adj[a] = push(a, b);
	}
	dfs();
	print_topo();
	print_adjlist();
	return 0;
}
