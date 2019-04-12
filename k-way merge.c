#include<stdio.h>
#include<time.h>
#include<math.h>

struct a{
    int val;
    int index;
};

int s;

void swap(struct a *a, struct a *b)
{
    struct a t=*a;
    *a=*b;
    *b=t;
}

int lchild(int i)
{
    return 2*i;
}

int rchild(int i)
{
    return 2*i+1;
}

void min_heapify(struct a arr[] ,int i)
{
    int l = lchild(i);
    int r = rchild(i);
    int min = i;
    if(l<=s && arr[l].val<arr[min].val)
        min=l;
    if(r<=s && arr[r].val<arr[min].val)
        min=r;
    if(min!=i)
    {
        swap(&arr[i],&arr[min]);
        min_heapify(arr, min);
    }
}

void constructHeap(struct a heap[])
{
    int i=0;
    for(i=s/2;i>0;i--)
        min_heapify(heap,i);
}

int main()
{
    int i,j,t,l;
    int n,k;
    printf("Enter n,k: ");
    scanf("%d %d",&n,&k);
    int arr[n][k];
    int res[n*k+1];
    printf(":Enter array:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int pt[n];
    struct a heap[n+1];
    for(i=0;i<n;i++)
    {
        pt[i]=0;
    }
    for(i=0;i<n;i++)
    {
        heap[i+1].val=arr[i][pt[i]];
        heap[i+1].index=i;
    }
    s=k;
    constructHeap(heap);
    i=0;
    while(i!=n*k)
    {
        struct a temp = heap[1];
        res[i++]=temp.val;
        pt[temp.index]++;
        s=0;
        l=0;
        for(j=0;j<n;j++)
        {
            if(pt[j]<k)
            {
                s++;
                heap[++l].val=arr[j][pt[j]];
                heap[l].index=j;
            }
        }
        constructHeap(heap);
    }
    printf("Output: ");
    for(i=0;i<n*k;i++)
    {
        printf("%d ",res[i]);
    }
    printf("\n");
}
