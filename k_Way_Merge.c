#include<stdio.h>

void swap(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}


void heapify(int arr[][2], int n, int i)
{
    int smallest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  

    
    if (l < n && arr[l][0] < arr[smallest][0])
        smallest = l;

    
    if (r < n && arr[r][0] < arr[smallest][0])
        smallest = r;

    
    if (smallest != i)
    {
        swap(&arr[i][0], &arr[smallest][0]);
	swap(&arr[i][1], &arr[smallest][1]);
        heapify(arr, n, smallest);
    }
}


void printarray(int arr[], int n)
{
    int i;
       for (i=0; i<n; ++i)
        printf("%d ",arr[i]);
}

int main()
{
	int n,k,i,j,count=0;
	printf("Enter the number of sorted arrays and their sizes :");
	scanf("%d%d",&n,&k);
	int a[n][k],c[n*k];
	for(i=0;i<n;i++)
	{
		printf("Enter the k elements into %d array :",i+1);
		for(j=0;j<k;j++)
			scanf("%d",&a[i][j]);
	}
	int b[n][2];
	int index[n];
	for(i=0;i<n;i++)
	{
		b[i][0]=a[i][0];
		b[i][1]=i;
		index[i]=1;
	}
	for (i = n / 2 - 1; i >= 0; i--)
        heapify(b, n, i);
	while(count<n*k)
	{
		c[count++]=b[0][0];
		if(index[b[0][1]]<k)
			b[0][0]=a[b[0][1]][index[b[0][1]]++];
		else
			b[0][0]=1000000;
		heapify(b, n, 0);
	}
	printarray(c, n*k);
	return 0;
}

