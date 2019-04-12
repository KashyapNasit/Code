#include<stdio.h>
int graph[10][10];
int visited[100];
int graph2[10][10];
int u[10],w[10];
int cu=0,cw=0;
void init(){
  int i,j;
  for(i=0;i<100;i++){
    visited[i]=0;
  }
}
void dfs(int i){
  visited[i]=1;
  int j;
  for(j=0;j<10;j++){
    if(graph2[i][j]!=0){
      if(!visited[j]){
        dfs(j);
      }
    }
  }
}
void print_dfs(int i){
  printf("%d ",i);
  visited[i]=1;
  int j;
  for(j=0;j<10;j++){
    if(graph2[i][j]!=0){
      if(!visited[j]){
        print_dfs(j);
      }
    }
  }
}
void prim(){
  u[cu++]=w[--cw];
  w[cw]=-1;
  while(cu<=cw){
    int i,j;
    int p,q;
    int min=100000;
    for(i=0;i<cu;i++){
      for(j=0;j<cw;j++){
        if(w[j]==-1)
        continue;
        if(graph[u[i]][w[j]]==0)
        continue;
        init();
        dfs(u[i]);
        if(visited[j]==0){
          if(min>graph[u[i]][w[j]]){
            min=graph[u[i]][w[j]];
            p=w[j];
            q=u[i];
          }
        }
      }
    }
    graph2[q][p]=graph2[p][q]=min;
    u[cu++]=w[p];
    w[p]=-1;
  }
  init();
  printf("DFS of MST: ");
  print_dfs(u[0]);
}
int main(){
  int i,j,k=0;
  printf("Enter edges(-1, -1, -1 to stop):\n");
  while(i!=-1&&j!=-1&&k!=-1){
    scanf("%d %d %d",&i,&j,&k);
    if(i<0||j<0||k<0)
    break;
    graph[i][j]=k;
    graph[j][i]=k;
  }
  i=0;
  printf("Enter nodes: ");
  while(i!=-1){
    scanf("%d",&i);
    if(i==-1)
    break;
    w[cw++]=i;
  }
  prim();
  printf("\n");
}
