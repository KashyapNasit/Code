#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int w[1000],n;

void sum_of_subset(int S,int R,int k,int M,int x[])
{
    if(k==n)
        return;
    int i;
    x[k]=1;
    if((S+w[k])==M)
    {
        printf("Solution:-\n");
        for(i=0;i<n;i++)
        {
            if(x[i]==1)
                printf("%d ",w[i]);
        }
        printf("\n");
        return;
    }
    if(((R-w[k])>=(M-(S+w[k]))) && ((S+w[k]+w[k+1])<=M))
    {
        sum_of_subset(S+w[k],R-w[k],k+1,M,x);
    }
    else
        if(((R-w[k])>=(M-S)) && ((S+w[k+1])<=M))
        {
            x[k]=0;
            sum_of_subset(S,R-w[k],k+1,M,x);
        }
}

int main()
{
    int i,M,S=0,x[1000];
    printf("Enter the size of array ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        S=S+w[i];
        x[i]=0;
    }
    printf("Enter the sum \n");
    scanf("%d",&M);
    sum_of_subset(0,S,0,M,x);
    return 0;
}
