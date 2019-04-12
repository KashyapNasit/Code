#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long A[1000000];

void swap(long *a,long *b)
{
	long t=*a;
	*a=*b;
	*b=t;
}

void generateBest(long size)
{
	long i,j;
	FILE *output;
	output = fopen("best","w");
	for(i=1;i<=size;i++)
	{
		fprintf(output,"%ld\n",i);
	}
	fclose(output);
}

void generateWorst(long size)
{
	long i,j;
	FILE *output;
	output = fopen("worst","w");
	for(i=size;i>0;i--)
	{
		fprintf(output,"%ld\n",i);
	}
	fclose(output);
}

void generateAverage(long size)
{
	long i,j;
	FILE *output;
	output = fopen("avg","w");
	for(i=1;i<=size;i++)
	{
		fprintf(output,"%ld\n",(rand()%size)+1);
	}
	fclose(output);
}

void merge(int l, int m, int r) {
    int ll = m-l+1, rr = r-m;
    int la[ll + 1], ra[rr + 1], i, j, k;
    for(i = 0; i < ll; i++) {
        la[i] = A[l + i];
    }
    la[i] = 10000000;
    for(j = 0; j < rr; j++) {
        ra[j] = A[m + j + 1];
    }
    ra[j] = 10000000;
    for(k = l, i = 0, j = 0; k < r; k++) {
        if(la[i] <= ra[j]) {
            A[k] = la[i++];
        }
        else {
            A[k] = ra[j++];
        }
    }
}

void merge_sort(int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        merge_sort(l, m);
        merge_sort(m+1, r);
        merge(l, m, r);
    }
}

int main()
{
	clock_t start_t,end_t;
	long i,j,temp;
	FILE *input,*output;
	output = fopen("merge_sort_best","w");
	printf("Merge Sort Best\n");
	for(i=100000;i<=1000000;i+=100000)
	{
		printf("size=%ld ",i);
		generateBest(i);
		input = fopen("best","r");
		for(j=0;j<i;j++)
		{
			fscanf(input,"%ld",&temp);
			A[j]=temp;
		}
		start_t = clock();
		merge_sort(0,i-1);
		end_t = clock();
		fprintf(output,"%lf\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		printf("time = %lf sec\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		fclose(input);
	}
	fclose(output);
	
	output = fopen("merge_sort_worst","w");
	printf("Merge Sort Worst\n");
	for(i=100000;i<=1000000;i+=100000)
	{
		printf("size=%ld ",i);
		generateWorst(i);
		input = fopen("worst","r");
		for(j=0;j<i;j++)
		{
			fscanf(input,"%ld",&temp);
			A[j]=temp;
		}
		start_t = clock();
		merge_sort(0,i-1);
		end_t = clock();
		fprintf(output,"%lf\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		printf("time = %lf sec\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		fclose(input);
	}
	fclose(output);
	
	output = fopen("merge_sort_avg","w");
	printf("Merge Sort Average\n");
	for(i=100000;i<=1000000;i+=100000)
	{
		printf("size=%ld ",i);
		generateAverage(i);
		input = fopen("avg","r");
		for(j=0;j<i;j++)
		{
			fscanf(input,"%ld",&temp);
			A[j]=temp;
		}
		start_t = clock();
		merge_sort(0,i-1);
		end_t = clock();
		fprintf(output,"%lf\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		printf("time = %lf sec\n",((double)(end_t-start_t))/CLOCKS_PER_SEC);
		fclose(input);
	}
	fclose(output);
}
