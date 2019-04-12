#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void QuickSort(int arr[], int l, int u) 
{ 
	while (l < u) 
	{ 
		
		int q = Partition(arr, l, u); 
		if (q - l < u - q) 
		{ 
			QuickSort(arr, l, q - 1); 
			l = q + 1; 
		} 
		else
		{ 
			QuickSort(arr, q + 1, u); 
			u = q - 1; 
		} 
	} 
} 

int Partition (int arr[],int l,int u)
{
    int i,j,pivot,temp;
    pivot = arr[u];  
    i = (l - 1);
    for (j = l; j <= u- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[u];
    arr[u]=temp;
    return (i + 1);
}


int main()
{
	int n,a[100000],i;
	printf("ENTER SIZE:\n");
	scanf("%d",&n);
	printf("ENTER ARRAY");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	QuickSort(a,0,n-1);
	printf("SORTED ARRAY\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
