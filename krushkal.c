#include<stdio.h>
int graph[100][100];
int arri[100],arrj[100],arrw[100];
int visited[10000];
void init(){
  int i,j;
  for(i=0;i<10000;i++){
    visited[i]=0;
  }
}
void dfs(int i){
  visited[i]=1;
  int j;
  for(j=0;j<100;j++){
    if(graph[i][j]!=0){
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
  for(j=0;j<100;j++){
    if(graph[i][j]!=0){
      if(!visited[j]){
        print_dfs(j);
      }
    }
  }
}
void bubble_sort(int arr[],int n,int
  arr1[],int arr2[]){
    int i,j,k,swap=0;
    for(i=1;i<n;i++){
      swap=0;
      for(j=0;j<n-i;j++){
        if(arr[j]>arr[j+1]){
          int t=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=t;
          t=arr1[j];
          arr1[j]=arr1[j+1];
          arr1[j+1]=t;
          t=arr2[j];
          arr2[j]=arr2[j+1];
          arr2[j+1]=t;
          swap=1;
        }
      }
      if(!swap)
      break;
    }
  }

  void krushkal(int c){
    int i;
    bubble_sort(arrw,c,arri,arrj);
    for(i=0;i<c;i++){
      init();
      dfs(arri[i]);
      if(visited[arrj[i]]==0){
        graph[arri[i]][arrj[i]]=arrw[i];
        graph[arrj[i]][arri[i]]=arrw[i];
      }
    }
    init();
    print_dfs(arri[0]);
  }
  int main(){
    int i,j,k=0;
    int c=0;
    printf("Enter edges(-1, -1, -1 to stop):\n");
    while(i!=-1&&j!=-1&&k!=-1){
      scanf("%d %d %d",&i,&j,&k);
      if(i<0||j<0||k<0)
      break;
      arri[c]=i;
      arrj[c]=j;
      arrw[c++]=k;
    }
    krushkal(c);
    printf("\n");
  }
