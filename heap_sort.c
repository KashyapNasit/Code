#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A[1000000];
int SIZE;

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int left_child(int i) {
	return 2*i;
}

int right_child(int i) {
	return 2*i+1;
}

void heapify(int i) {
	int max = i;
	int lchild = left_child(i);
	int rchild = right_child(i);
	if(lchild <= SIZE && A[lchild] > A[max]) {
		max = lchild;
	}
	if(rchild <= SIZE && A[rchild] > A[max]) {
		max = rchild;
	}
	if(max != i) {
		swap(&A[i], &A[max]);
		heapify(max);
	}
}

void build_maxheap() {
	int i;
	for(i = SIZE/2; i >= 1; i--) {
		heapify(i);
	}
}

void heap_sort(int n) {
	build_maxheap();
	SIZE = n;
	int i;
	for(i = SIZE; i >= 2; i--) {
		swap(&A[1], &A[i]);
		n--;
		heapify(1);
	}
}

void generateBest(int size)
{
	int i,j;
	FILE *output;
	output = fopen("best","w");
	for(i=1;i<=size;i++)
	{
		fprintf(output,"%d\n",i);
	}
	fclose(output);
}

void generateWorst(int size)
{
	int i,j;
	FILE *output;
	output = fopen("worst","w");
	for(i=size;i>0;i--)
	{
		fprintf(output,"%d\n",i);
	}
	fclose(output);
}

void generateAverage(int size)
{
	int i,j;
	FILE *output;
	output = fopen("avg","w");
	for(i=1;i<=size;i++)
	{
		fprintf(output,"%d\n",(rand()%size)+1);
	}
	fclose(output);
}

int main()
{
	clock_t start_t,end_t;
	int i,j,temp;
	FILE *input,*output;
	output = fopen("heap_sort_best","w");
	printf("Heap Sort Best\n");
	for(i=100000;i<=1000000;i+=100000)
	{
		printf("size=%d ",i);
		generateBest(i);
		input = fopen("best","r");
		for(j=0;j<i;j++)
		{
			fscanf(input,"%d",&temp);
			A[j]=temp;
		}
		start_t = clock();
		heap_sort(i);
		end_t = clock();
		fprintf(output,"%lf\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		printf("time = %lf sec\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		fclose(input);
	}
	fclose(output);
	
	output = fopen("heap_sort_worst","w");
	printf("Heap Sort Worst\n");
	for(i=100000;i<=1000000;i+=100000)
	{
		printf("size=%d ",i);
		generateWorst(i);
		input = fopen("worst","r");
		for(j=0;j<i;j++)
		{
			fscanf(input,"%d",&temp);
			A[j]=temp;
		}
		start_t = clock();
		heap_sort(i);
		end_t = clock();
		fprintf(output,"%lf\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		printf("time = %lf sec\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		fclose(input);
	}
	fclose(output);
	
	output = fopen("heap_sort_avg","w");
	printf("Heap Sort Average\n");
	for(i=100000;i<=1000000;i+=100000)
	{
		printf("size=%d ",i);
		generateAverage(i);
		input = fopen("avg","r");
		for(j=0;j<i;j++)
		{
			fscanf(input,"%d",&temp);
			A[j]=temp;
		}
		start_t = clock();
		heap_sort(i);
		end_t = clock();
		fprintf(output,"%lf\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		printf("time = %lf sec\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		fclose(input);
	}
	fclose(output);
}