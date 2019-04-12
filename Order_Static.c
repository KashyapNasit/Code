#include<stdio.h>

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
/*
void printarr(int arr[],int n){
	int i;
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
}
*/
int partition(int arr[], int lb, int ub){
	int ll=lb-1;
	int pivot=arr[ub];
	int i;
	for(i=lb;i<ub;++i)
		if(arr[i]<pivot)
			swap(&arr[i],&arr[++ll]);
	swap(&arr[++ll],&arr[ub]);
	//printarr(arr,9);
	return ll;
}

int iTon(int arr[],int lb, int ub, int i){
	if(lb==ub)
		return arr[lb];
	if(lb>ub)
		return -1;
	int q = partition(arr,lb,ub);
	int abs=q-lb+1;
	if(abs==i)
		return arr[q];
	else if(abs>i)
		return iTon(arr,lb,q-1,i);
	else
		return iTon(arr,q+1,ub,i-abs);
}
/*
void quickSort(int arr[],int lb, int ub){
	if(lb>ub)
		return;
	
	int q = partition(arr,lb,ub);
	quickSort(arr,q+1,ub);
	quickSort(arr,lb,q-1);
}
*/
int main(){
	int arr[]={9,1,8,2,7,3,4,6,5};
	//quickSort(arr,0,8);
	
	//printarr(arr,9);
	int i;
	scanf("%d",&i);
	//printf("%d",partition(arr,0,8));
	printf("%d",iTon(arr,0,8,i));
	return 0;
}
