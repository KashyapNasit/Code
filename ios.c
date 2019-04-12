#include<stdio.h>

int min,max;
int size;

void calc_min_max(int arr[])
{
	if(size<2)
		return ;
	if(arr[0]<arr[1])
	{
		min=arr[0];
		max=arr[1];
	}
	else
	{
		min=arr[1];
		max=arr[0];
	}
	int i,flag=0;
	if(size%2!=0){
		flag=1;
		size--;
	}
	for(i=2;i<size;i+=2)
	{
		if(arr[i]<arr[i+1])
		{
			if(arr[i]<min)
				min=arr[i];
			if(arr[i+1]>max)
				max=arr[i+1];
		}
		else
		{
			if(arr[i+1]<min)
				min=arr[i+1];
			if(arr[i]>max)
				max=arr[i];	
		}
	}
	if(flag){
		size++;
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
}

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int arr[], int l, int r)
{
	int pivot=arr[r];
	int i;
	int ll=l-1;
	for(i=l;i<r;i++)
	{
		if(arr[i]<=pivot)
		{
			ll++;
			swap(&arr[ll],&arr[i]);
		}
	}
	ll++;
	swap(&arr[ll],&arr[r]);
	return ll;
}

int i_small(int arr[], int l, int r, int i)
{
	if(l==r)
		return arr[l];
	if(l>r)
		return -1000;
	int q = partition(arr,l,r);
	if(q==i)
		return arr[q];
	else if(q<i)
		return i_small(arr,q+1,r,i);
	else
		return i_small(arr,l,q-1,i);
}

int main()
{
	int i;
	printf("Enter size of array: ");
	scanf("%d",&size);
	printf("Enter array: ");
	int arr[size];
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	calc_min_max(arr);
	printf("1. Smallest: %d\n",min);
	printf("2. Largest: %d\n",max);
	while(1)
	{
		printf("Enter i: ");
		scanf("%d",&i);
		if(i<0||i>size)
			return 0;
		printf("ith smallest: %d\n",i_small(arr,0,size-1,i-1));
	}
	return 0;
}