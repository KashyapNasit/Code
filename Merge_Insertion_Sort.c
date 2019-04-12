#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Merge(int arr[],int L,int m, int U)
{
	int ll = m-L+1;
	int rl = U-m;
	int Tl[ll+1];
	int Tr[rl+1];
	int i,j,k;
	for(i=0;i<ll;++i)
		Tl[i]=arr[L+i];
	for(j=0;j<rl;++j)
		Tr[j]=arr[m+j+1];
	Tl[ll]=INT_MAX;
	Tr[rl]=INT_MAX;
	i=j=0;
	for(k=L;k<=U;++k){
		if(Tl[i] <= Tr[j])
			arr[k]=Tl[i++];
		else
			arr[k]=Tr[j++];
	}
}

void InsertionSort(int arr[], int l, int u) 
{ 
   int i, key, j; 
   for (i = l+1; i < u; i++) 
   { 
       key = arr[i]; 
       j = i-1;
       while (j >= l && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       }
       arr[j+1] = key; 
   } 
}

void MergeSort(int arr[],int l, int u,int k)
{
	int m;
	if((u-l) <= k)
		InsertionSort(arr,l,u);
	else
	{
		m=(l+u)/2;
		MergeSort(arr,l,m,k);
		MergeSort(arr,m+1,u,k);
		Merge(arr,l,m,u);
	}
}

int main()
{
	int n,a[100000],i,k;
	printf("ENTER SIZE:\n");
	scanf("%d",&n);
	printf("ENTER ARRAY");
	printf("ENTER k:");
	scanf("%d",&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	MergeSort(a,0,n,k);
	printf("SORTED ARRAY\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
