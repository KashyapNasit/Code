#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *root=NULL;
int visited[20];
int dist[20];
int pt[20];
int mat[20][20];
int n;
void initgraph(int s)
{
    int i;
    for(i=0;i<n;i++)
    {
        dist[i]=-1e6;
        pt[i]=-1;
    }
    dist[s]=0;
}
void relax(int u,int v)
{
    if(dist[v]<dist[u]+mat[u][v])
    {
        pt[v]=u;
        dist[v]=dist[u]+mat[u][v];
        pt[v]=u;
    }
}
void push(int x)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=x;
    tmp->next=NULL;
    if(root==NULL)
    {
        root=tmp;
        return;
    }
    else
    {
        tmp->next=root;
        root=tmp;
    }
}
int pop()
{
    if(root!=NULL)
    {
        int d=root->data;
        struct node *tmp1=root;
        root=root->next;
        free(tmp1);
        return d;
    }
}
void toposort(int v)
{
    visited[v]=1;
    int i;
    for(i=0;i<n;i++)
    {
        if(mat[v][i]!=0&&visited[i]==0)
        {
            toposort(i);
        }
    }
    push(v);
}
void critpath(int s)
{
    toposort(s);
    initgraph(s);
    while(root!=NULL)
    {
        int u=pop();
        int i;
        if(dist[u]!=(-1e6))
        {
            for(i=0;i<n;i++)
            {
                if(mat[u][i]!=0)
                {
                    relax(u,i);
                }
            }
        }
    }
}
int main()
{
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    printf("enter edges in source---destination----->weight format and -1 -1 to quit\n");
    int i,j;
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            mat[i][j]=0;
        }
    }
    while(1)
    {
        int s,d,w;
        scanf("%d%d%d",&s,&d,&w);
        if((s==-1)||(d==-1))
            break;
        else
            mat[s][d]=w;
    }
    for(i=0;i<20;i++)
        visited[i]=0;
    printf("enter source vertex\n");
    int s;
    scanf("%d",&s);
    critpath(s);
    printf("distance of nodes from source vertex are\n");
    for(i=0;i<n;i++)
    {
        printf("%d, %d   %d\n",s,i,dist[i]);
    }
    return 0;
}
