#include<stdio.h>

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void knapsack(int n, int M, int w[], int p[], double x[])
{
	int d[n+1],i,j;
	int loc[n+1];
	double X[n+1];
	for(i=0;i<n;i++)
	{
		d[i]=p[i]/w[i];
		loc[i]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(d[i]<d[j])
			{
				swap(&p[i],&p[j]);
				swap(&w[i],&w[j]);
				swap(&d[i],&d[j]);
				swap(&loc[i],&loc[j]);
			}
		}
	}

	int sum=0;
	for(i=0;i<n;i++)
		X[i]=0;
	for(i=0;i<n;i++)
	{
		if(sum+w[i]<M)
		{
			X[i]=1;
			sum+=w[i];
		}
		else
		{
			X[i]=(double)(M-sum)/w[i];
			break;
		}
	}

	for(i=0;i<n;i++)
	{
		x[loc[i]]=X[i];
	}
}

int main()
{
	int i,no,m,w[100],p[100];
	double x[100];
	printf("Enter no of items and weight a bag can carry: ");
	scanf("%d %d",&no,&m);
	printf("Enter weight and profit of items respectively:\n");
	for(i=0;i<no;i++)
	{
		scanf("%d %d",&w[i],&p[i]);
	}
	knapsack(no,m,w,p,x);
	printf("\nItems to be taken: ");
	for(i=0;i<no;i++)
	{
		printf("\n(Weight=%dKg, Value=$%d, Profit=$%0.2lf, taken=%0.2lfKg)",w[i],p[i],p[i]*x[i],x[i]*w[i]);
	}
	printf("\n");
}